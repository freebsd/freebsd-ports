#!/bin/sh
#
# An rc.subr-style startup script for Courier-IMAP's IMAP over SSL service.

# PROVIDE: courier_imap_imapd_ssl
# REQUIRE: LOGIN courier_authdaemond
# KEYWORD: FreeBSD shutdown

# Define these courier_imap_imapd_ssl_* variables in one of these files:
# 	/etc/rc.conf
# 	/etc/rc.conf.local
# 	/etc/rc.conf.d/courier_imap_imapd_ssl
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE

courier_imap_imapd_ssl_enable=${courier_imap_imapd_ssl_enable-"NO"}

. %%RC_SUBR%%

name="courier_imap_imapd_ssl"
rcvar=`set_rcvar`
command="%%PREFIX%%/libexec/courier-imap/imapd-ssl.rc"
pidfile="/var/run/imapd-ssl.pid"
procname="%%PREFIX%%/libexec/courier-imap/couriertcpd"

start_cmd="imapd_ssl_cmd start"
stop_cmd="imapd_ssl_cmd stop"
restart_cmd="imapd_ssl_cmd stop && imapd_ssl_cmd start"

load_rc_config $name

imapd_ssl_cmd () {
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

