#!/bin/sh
# $FreeBSD$

# PROVIDE: smartd
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown

# Define these smartd_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/smartd
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
smartd_enable="NO"
smartd_flags=""
smartd_pidfile="/var/run/smartd.pid"

. %%RC_SUBR%%

name="smartd"
rcvar=`set_rcvar`
command="%%PREFIX%%/sbin/smartd"
required_files="%%PREFIX%%/etc/smartd.conf"

load_rc_config $name

pidfile="${smartd_pidfile}"

case "${smartd_flags}" in
*-p\ *)
	echo "ERROR: \$smartd_flags includes -p option." \
		"Please use \$smartd_pidfile instead."
	exit 1
	;;
*)
	smartd_flags="-p ${pidfile} ${smartd_flags}"
	;;
esac

run_rc_command "$1"
