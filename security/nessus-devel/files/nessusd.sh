#!/bin/sh

# Start or stop nessusd
# $FreeBSD$

# PROVIDE: nessusd
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown
#
# NOTE for FreeBSD 5.0+:
# If you want this script to start with the base rc scripts
# move nessusd.sh to /etc/rc.d/nessusd

prefix=%%PREFIX%%

# Define these nessusd_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/nessusd
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
[ -z "$nessusd_enable" ] && nessusd_enable="NO"	# Disable nessusd
#nessusd_program="${prefix}/sbin/nessusd"	# Location of nessusd
nessusd_flags="-D"				# Flags to nessusd program

. %%RC_SUBR%%

name="nessusd"
rcvar=`set_rcvar`
command="${prefix}/sbin/nessusd"
pidfile="/usr/local/var/nessus/nessusd.pid"
required_files="${prefix}/etc/nessus/nessusd.conf"

load_rc_config $name
run_rc_command "$1"
