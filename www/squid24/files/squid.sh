#!/bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/www/squid24/files/Attic/squid.sh,v 1.4 2004-02-18 12:25:09 sergei Exp $
#
# PROVIDE: squid
# REQUIRE: NETWORKING SERVERS
# BEFORE: DAEMON
# KEYWORD: FreeBSD
# 
# Note:
# If you are running an rcNG-System (i.e. FreeBSD 5 and later or after
# having installed the rc_subr-port on an earlier system) you must set
# "squid_enable=YES" in either /etc/rc.conf, /etc/rc.conf.local or
# /etc/rc.conf.d/squid to make this script actually do something. There
# you can also set squid_chdir, squid_user, and squid_flags.
#
# Please see squid(8), rc.conf(5) and rc(8) for further details.

unset rcNG
name="squid"
command=%%PREFIX%%/sbin/squid
extra_commands=reload
reload_cmd="${command} -k reconfigure"
stop_cmd="${command} -k shutdown"
: ${squid_chdir:=%%PREFIX%%/squid/logs}
: ${squid_user:=%%SQUID_UID%%}
: ${squid_flags:="-D"}
default_config=%%PREFIX%%/etc/squid/squid.conf

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
	# check that squid's default configuration is present when
	# squid_flags is not set. We assume that you specify at
	# least the path to your non-default configuration with
	# '-f /path/to/config.file' in squid_flags if you delete this file.
	if [ -z "${squid_flags}" ]; then
		required_files=${default_config}
	fi
	required_dirs=${squid_chdir}
	run_rc_command "$1"
else
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
		echo "usage: `basename $0` {start|stop}" >&2
		exit 64
		;;
	esac
	exit 0
fi
