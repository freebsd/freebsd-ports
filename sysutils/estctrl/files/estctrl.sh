#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: estctrl
# REQUIRE: est
# KEYWORD: FreeBSD

# Define estctrl_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/est
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
estctrl_enable="NO"
estctrl_speed_ac="adaptive"
estctrl_speed_battery="adaptive"
estctrl_speed_default="adaptive"

. %%RC_SUBR%%

name="estctrl"
rcvar=`set_rcvar`

load_rc_config $name

command="%%PREFIX%%/sbin/estctrl"
command_args="-a ${estctrl_speed_ac}"
command_args="${command_args} -b ${estctrl_speed_battery}"
command_args="${command_args} -d ${estctrl_speed_default}"
command_args="${command_args} &"

run_rc_command "$1"
