#!/bin/sh

# Start or stop racoon
# $FreeBSD$

# PROVIDE: racoon
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown
#
# NOTE for FreeBSD 5.0+:
# If you want this script to start with the base rc scripts
# move racoon.sh to /etc/rc.d/racoon

prefix=%%PREFIX%%

# Define these racoon_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/racoon
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
[ -z "$racoon_enable" ] && racoon_enable="YES"	# Enable racoon
#racoon_program="${prefix}/sbin/racoon"		# Location of racoon
#racoon_flags=""				# Flags to racoon program

. %%RC_SUBR%%

name="racoon"
rcvar=`set_rcvar`
command="${prefix}/sbin/racoon"
pidfile="/var/run/racoon.pid"
required_files="${prefix}/etc/racoon/racoon.conf"
stop_postcmd="racoon_poststop"

racoon_poststop() {
	/bin/rm -f ${pidfile}
}

load_rc_config $name
run_rc_command "$1"
