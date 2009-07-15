#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: ekpd
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: shutdown

# Define these ekpd_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/ekpd
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
# ekpd_enable="YES"
# ekpd_flags=""			# Flags to ekpd program

. %%RC_SUBR%%

name="ekpd"
rcvar=`set_rcvar`
command="%%PREFIX%%/libexec/pips/printer/ekpd"
start_precmd="ekpd_prestart"

ekpd_prestart() {
	OLDMASK=`umask`
	umask 000
	[ ! -d /var/ekpd ] && mkdir -p /var/ekpd && chmod 1777 /var/ekpd
	[ ! -e /var/ekpd/ekplp0 ] && rm -f /var/ekpd/ekplp0 && \
		mkfifo -m 666 /var/ekpd/ekplp0
	umask $OLDMASK
}

load_rc_config $name
ekpd_enable=${ekpd_enable:-"NO"}
run_rc_command "$1"
