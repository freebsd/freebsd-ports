#!/bin/sh
#
# An rc.subr-style startup script for Courier-IMAP's IMAP service.

# PROVIDE: courier_imap_imapd
# REQUIRE: LOGIN courier_authdaemond
# KEYWORD: FreeBSD shutdown

# Define these courier_imap_imapd_* variables in one of these files:
# 	/etc/rc.conf
# 	/etc/rc.conf.local
# 	/etc/rc.conf.d/courier_imap_imapd
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE

courier_imap_imapd_enable=${courier_imap_imapd_enable-"NO"}

. %%RC_SUBR%%

name="courier_imap_imapd"
rcvar=`set_rcvar`
command="%%PREFIX%%/libexec/courier-imap/imapd.rc"
pidfile="/var/run/imapd.pid"
procname="%%PREFIX%%/libexec/courier-imap/couriertcpd"

start_cmd="imapd_cmd start"
stop_cmd="imapd_cmd stop"
restart_cmd="imapd_cmd stop && imapd_cmd start"

load_rc_config $name

imapd_cmd () {
	case $1 in
	start)
		echo "Starting ${name}."
		${command} start
		;;
	stop)
		echo "Stopping ${name}."
		${command} stop
		;;
	esac
}

run_rc_command "$1"

