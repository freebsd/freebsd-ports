#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: oops
# REQUIRE: DAEMON
# KEYWORD: FreeBSD

. "%%RC_SUBR%%"

name="oops"
rcvar=`set_rcvar`

command="%%PREFIX%%/sbin/oopsctl"
procname="%%PREFIX%%/sbin/oops"
pidfile="/var/run/oops/oops.pid"

required_files="%%PREFIX%%/etc/oops/oops.cfg"
required_dirs="/var/run/oops"

extra_commands="reconfig rotate"

start_cmd="start_cmd"
stop_cmd="stop_cmd"
reconfig_cmd="reconfig_cmd"
rotate_cmd="rotate_cmd"

start_cmd()	{
	${command} start 2>&1 > /dev/null
}

stop_cmd()	{
	${command} stop
}

reconfig_cmd()	{
	${command} reconfigure
}

rotate_cmd()	{
	${command} rotate
}

load_rc_config "oops"
: ${oops_enable="NO"}

run_rc_command "$1"
