#!/bin/sh
# $FreeBSD$

# PROVIDE: smartd
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: shutdown

# Define these smartd_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/smartd
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
smartd_enable="${smartd_enable-NO}"
smartd_pidfile="/var/run/smartd.pid"

. %%RC_SUBR%%

name="smartd"
rcvar=`set_rcvar`
command="%%PREFIX%%/sbin/smartd"

load_rc_config $name

: ${smartd_config="%%PREFIX%%/etc/smartd.conf"}
: ${smartd_flags="-c ${smartd_config}"}

pidfile="${smartd_pidfile}"
required_files="${smartd_config}"

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
