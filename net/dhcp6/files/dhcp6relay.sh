#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: dhcp6relay
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown
#
# NOTE for FreeBSD 5.0+:
# If you want this script to start with the base rc scripts
# move dhcp6relay.sh to /etc/rc.d/dhcp6relay

prefix=%%PREFIX%%

# Define these dhcp6relay_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/dhcp6relay
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
dhcp6relay_enable=${dhcp6relay_enable:-"NO"}	# Enable dhcp6relay
#dhcp6relay_program="${prefix}/sbin/${name}"	# Location of dhcp6relay
#dhcp6relay_flags="-r fxp1 fxp0"		# Flags to dhcp6relay program

. %%RC_SUBR%%

name="dhcp6relay"
rcvar=`set_rcvar`
command="${prefix}/sbin/${name}"

load_rc_config $name
run_rc_command "$1"
