#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: dhcp6s
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown
#
# NOTE for FreeBSD 5.0+:
# If you want this script to start with the base rc scripts
# move dhcp6s.sh to /etc/rc.d/dhcp6s

prefix=%%PREFIX%%

# Define these dhcp6s_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/dhcp6s
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
dhcp6s_enable=${dhcp6s_enable:-"NO"}		# Enable dhcp6s
#dhcp6s_program="${prefix}/sbin/${name}"	# Location of dhcp6s
#dhcp6s_flags="fxp0"				# Flags to dhcp6s program

. %%RC_SUBR%%

name="dhcp6s"
rcvar=`set_rcvar`
command="${prefix}/sbin/${name}"
required_files="${prefix}/etc/${name}.conf"

load_rc_config $name
run_rc_command "$1"
