#!/bin/sh
#
# An rc.subr-style startup script for Courier-IMAP's POP3 over SSL service.

# PROVIDE: courier_imap_pop3dssl
# REQUIRE: LOGIN
# KEYWORD: FreeBSD shutdown

# Define these courier_imap_pop3dssl_* variables in one of these files:
# 	/etc/rc.conf
# 	/etc/rc.conf.local
# 	/etc/rc.conf.d/courier_imap_pop3dssl
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE

courier_imap_pop3dssl_enable=${courier_imap_pop3dssl_enable-"NO"}

. %%RC_SUBR%%

name="courier_imap_pop3dssl"
rcvar=`set_rcvar`
command="%%PREFIX%%/libexec/courier-imap/pop3d-ssl.rc"

start_cmd="pop3dssl_cmd start"
stop_cmd="pop3dssl_cmd stop"
restart_cmd="pop3dssl_cmd stop && pop3dssl_cmd start"

load_rc_config $name

pop3dssl_cmd () {
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

