#!/bin/sh
#
# $FreeBSD$
#
# PROVIDE: netustad
# REQUIRE: NETWORKING SERVERS
# BEFORE: DAEMON
# KEYWORD: FreeBSD
#
# Note:
# If you are running an rcNG-System (i.e. FreeBSD 5 and later or after
# having installed the rc_subr-port on an earlier system) you must set
# "netustad_enable=YES" in either /etc/rc.conf, /etc/rc.conf.local or
#
# Please see netustad(8), rc.conf(5) and rc(8) for further details.

unset rcNG
name="netustad"
command=%%PREFIX%%/sbin/netustad
extra_commands=reload
reload_cmd="killall -HUP ${name}"
stop_cmd="killall ${name}"

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr && rcNG=yes
else
	if [ -f %%PREFIX%%/etc/rc.subr ]; then
		. %%PREFIX%%/etc/rc.subr && rcNG=yes
	fi
fi

if [ "${rcNG}" ]; then
	rcvar=`set_rcvar`
	load_rc_config ${name}
	run_rc_command "$1"
else
	case $1 in
	start)
		if [ -x "${command}" ]; then
			echo -n ' netustad '
			${command}
		fi
		;;
	stop)
		if [ -x "${command}" ]; then
			echo -n ' netustad '
			${stop_cmd}
		fi
		;;
		*)
		echo "usage: `basename $0` {start|stop}" >&2
		exit 64
		;;
	esac
	exit 0
fi
