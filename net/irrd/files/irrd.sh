#!/bin/sh
# $FreeBSD$

# PROVIDE: irrd
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown

# Define these irrd_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/irrd
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
irrd_enable="${irrd_enable:-NO}"		# Enable irrd
#irrd_program="%%PREFIX%%/sbin/irrd"		# Location of irrd
irrd_flags="${irrd_flags:--u}"			# Flags to imapd program

. %%RC_SUBR%%

name="irrd"
rcvar=`set_rcvar`
command="%%PREFIX%%/sbin/irrd"
required_files="%%PREFIX%%/etc/irrd.conf"

load_rc_config $name
run_rc_command "$1"
