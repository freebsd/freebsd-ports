#!/bin/sh
#
# An rc.subr-style startup script for courier-authdaemond service.

# PROVIDE: courier_authdaemond
# REQUIRE: LOGIN
# KEYWORD: FreeBSD shutdown

# Define these courier_authdaemond_* variables in one of these files:
# 	/etc/rc.conf
# 	/etc/rc.conf.local
# 	/etc/rc.conf.d/courier_authdaemond
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE

courier_authdaemond_enable=${courier_authdaemond_enable-"NO"}

. %%RC_SUBR%%

name="courier_authdaemond"
rcvar=`set_rcvar`
command="%%PREFIX%%/sbin/authdaemond"

start_cmd="authdaemond_cmd start"
stop_cmd="authdaemond_cmd stop"
restart_cmd="authdaemond_cmd stop && authdaemond_cmd start"
rundir=/var/run/authdaemond
pidfile="${rundir}/pid"
procname="%%PREFIX%%/sbin/courierlogger"

load_rc_config $name

authdaemond_cmd () {
	case $1 in
	start)
		if [ ! -d "${rundir}" ] ; then
			mkdir -p -m 0750 "${rundir}" && chown %%MAILUSER%%:%%MAILGROUP%% "${rundir}"
			if [ $? -ne 0 ] ; then
				echo "creating ${rundir} with the correct permissions was not possible!"
				return 1
			fi
		fi
		echo "Starting ${name}."
		${command} start
		;;
	stop)
		echo "Stopping ${name}."
		${command} stop
		if [ $? -eq 0 ] ; then
			[ -f "${pidfile}" ]       && rm -f "$pidfile"
			[ -f "${pidfile}.lock" ]  && rm -f "${pidfile}.lock"
			[ -S "${rundir}/socket" ] && rm -f "${rundir}/socket"
			return 0
		fi
		;;
	esac
}

run_rc_command "$1"

