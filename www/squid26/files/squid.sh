#!/bin/sh
#
# $FreeBSD$
#
# PROVIDE: squid
# REQUIRE: NETWORKING SERVERS
# BEFORE: DAEMON
# KEYWORD: FreeBSD shutdown
# 
# Note:
# If you are running an rcNG-System (i.e. FreeBSD 5 and later) you need to set
# "squid_enable=YES" in either /etc/rc.conf, /etc/rc.conf.local or
# /etc/rc.conf.d/squid to make this script actually do something. There
# you can also set squid_chdir, squid_user, and squid_flags.
#
# Please see squid(8), rc.conf(5) and rc(8) for further details.

name="squid"
command=%%PREFIX%%/sbin/squid
extra_commands=reload
reload_cmd="${command} -k reconfigure"
stop_cmd="${command} -k shutdown"
squid_chdir=${squid_chdir:-%%PREFIX%%/squid/logs}
squid_enable=${squid_enable:-"NO"}
squid_flags=${squid_flags-"-D"}
squid_user=${squid_user:-%%SQUID_UID%%}
default_config=%%PREFIX%%/etc/squid/squid.conf

if [ -f /etc/rc.subr ]; then
	# make use of rcNG features:
	. /etc/rc.subr
	rcvar=`set_rcvar`
	load_rc_config ${name}
	# squid(8) will not start if ${default_config} is not present so try
	# to catch that beforehand via ${required_files} rather than make
	# squid(8) crash.
	# If you remove the default configuration file make sure to add
	# '-f /path/to/your/squid.conf' to squid_flags
	if [ -z "${squid_flags}" ]; then
		required_files=${default_config}
	fi
	required_dirs=${squid_chdir}
	run_rc_command "$1"
else
	# implement the startup using the "old style" for non-rcNG-systems:
	case $1 in
	start)
		if [ -x "${command}" -a \
			\( -f "${default_config}" -o "${squid_flags}" \) ]; then
			echo -n ' squid'
			(cd ${squid_chdir} && exec su -fm ${squid_user} -c \
				"${command} ${squid_flags}")
		fi
		;;
	stop)
		if [ -x "${command}" ]; then
			echo -n ' squid'
			${stop_cmd}
			while ps -xcU ${squid_user} | grep -q squid; do
				sleep 2
			done
		fi
		;;
		*)
		echo "usage: ${0##*/} {start|stop}" >&2
		exit 64
		;;
	esac
	exit 0
fi
