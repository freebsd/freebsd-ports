#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: dhcp6c
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown
#
# NOTE for FreeBSD 5.0+:
# If you want this script to start with the base rc scripts
# move dhcp6c.sh to /etc/rc.d/dhcp6c

prefix=%%PREFIX%%

# Define these dhcp6c_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/dhcp6c
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
dhcp6c_enable=${dhcp6c_enable:-"NO"}		# Enable dhcp6c
#dhcp6c_program="${prefix}/sbin/${name}"	# Location of dhcp6c
#dhcp6c_flags="fxp0"				# Flags to dhcp6c program

. %%RC_SUBR%%

name="dhcp6c"
rcvar=`set_rcvar`
command="${prefix}/sbin/${name}"
required_files="${prefix}/etc/${name}.conf"

load_rc_config $name
run_rc_command "$1"
