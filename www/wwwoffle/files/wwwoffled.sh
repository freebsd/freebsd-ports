#!/bin/sh
# $FreeBSD$

# PROVIDE: wwwoffled
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown

# Define these wwwoffled_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/wwwoffled
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
wwwoffled_enable="NO"
wwwoffled_flags=""
wwwoffled_pidfile="/var/run/wwwoffled.pid"
wwwoffled_conffile="%%PREFIX%%/etc/wwwoffle.conf"

. %%RC_SUBR%%

name="wwwoffled"
rcvar=`set_rcvar`
command="%%PREFIX%%/sbin/wwwoffled"

load_rc_config $name

pidfile="${wwwoffled_pidfile}"
command_args="-p > ${pidfile} 2> /dev/null"
required_files="${wwwoffled_conffile}"
stop_postcmd="/bin/rm -f ${pidfile}"

run_rc_command "$1"
