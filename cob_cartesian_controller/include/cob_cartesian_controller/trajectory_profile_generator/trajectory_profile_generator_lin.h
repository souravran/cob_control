/*!
 *****************************************************************
 * \file
 *
 * \note
 *   Copyright (c) 2015 \n
 *   Fraunhofer Institute for Manufacturing Engineering
 *   and Automation (IPA) \n\n
 *
 *****************************************************************
 *
 * \note
 *   Project name: care-o-bot
 * \note
 *   ROS stack name: cob_control
 * \note
 *   ROS package name: cob_cartesian_controller
 *
 * \author
 *   Author: Christoph Mark, email: christoph.mark@ipa.fraunhofer.de / christoph.mark@gmail.com
 *
 * \date Date of creation: July, 2015
 *
 * \brief
 *   ...
 *
 ****************************************************************/

#ifndef COB_CARTESIAN_CONTROLLER_PROFILE_GENERATOR_LIN_H_
#define COB_CARTESIAN_CONTROLLER_PROFILE_GENERATOR_LIN_H_

#include <ros/ros.h>
#include <cob_cartesian_controller/cartesian_controller_data_types.h>
#include <cob_cartesian_controller/cartesian_controller_utils.h>


class TrajectoryProfileGeneratorLin
{
public:
    TrajectoryProfileGeneratorLin(double update_rate)
    {
        update_rate_ = update_rate;
        t_ipo_ = 1.0/update_rate;
    }
    
    ~TrajectoryProfileGeneratorLin()
    {}

    bool calculateProfile(std::vector<double>* path_matrix, double Se, double Se_roll, double Se_pitch, double Se_yaw, cob_cartesian_controller::MoveLinStruct& move_lin);

private:    
    bool calculateRampProfile(std::vector<double>* path_matrix, double Se, double Se_roll, double Se_pitch, double Se_yaw, cob_cartesian_controller::MoveLinStruct& move_lin);
    bool calculateSinoidProfile(std::vector<double>* path_matrix, double Se, double Se_roll, double Se_pitch, double Se_yaw, cob_cartesian_controller::MoveLinStruct& move_lin);

    bool generateRampPath(std::vector<double>& path_rray, double vel_max, double accel_max, double Se_max, int steps_max);
    bool generateSinoidPath(std::vector<double>& path_rray, double vel_max, double accel_max, double Se_max, int steps_max);

    bool generateRampPathWithTe(std::vector<double> &path_array, double te, double accl_max, double Se_max, int steps_max, double start_angle);
    bool generateSinoidPathWithTe(std::vector<double> &path_array, double te, double accl_max, double Se_max, int steps_max, double start_angle);

    double update_rate_;
    double t_ipo_;
};

#endif /* COB_CARTESIAN_CONTROLLER_PROFILE_GENERATOR_H_ */
