#!/bin/sh
#
# An rc.subr-style startup script for Courier-IMAP's IMAP over SSL service.

# PROVIDE: courier_imap_imapdssl
# REQUIRE: LOGIN
# KEYWORD: FreeBSD shutdown

# Define these courier_imap_imapdssl_* variables in one of these files:
# 	/etc/rc.conf
# 	/etc/rc.conf.local
# 	/etc/rc.conf.d/courier_imap_imapdssl
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE

courier_imap_imapdssl_enable=${courier_imap_imapdssl_enable-"NO"}

. %%RC_SUBR%%

name="courier_imap_imapdssl"
rcvar=`set_rcvar`
command="%%PREFIX%%/libexec/courier-imap/imapd-ssl.rc"

start_cmd="imapdssl_cmd start"
stop_cmd="imapdssl_cmd stop"
restart_cmd="imapdssl_cmd stop && imapdssl_cmd start"

load_rc_config $name

imapdssl_cmd () {
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

