#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: pips
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown

# Define these pips_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/pips
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
pips_enable=${pips_enable:-"YES"}		# Enable pips

. %%RC_SUBR%%

name="pips"
rcvar=`set_rcvar`
start_cmd="/sbin/ldconfig -m %%PREFIX%%/lib/pips"
stop_cmd=":"

load_rc_config $name
run_rc_command "$1"
