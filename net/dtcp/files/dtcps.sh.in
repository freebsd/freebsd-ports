#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: dtcps
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown
#
# NOTE for FreeBSD 5.0+:
# If you want this script to start with the base rc scripts
# move dtcps.sh to /etc/rc.d/dtcps

prefix=%%PREFIX%%

# Define these dtcps_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/dtcps
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
dtcps_enable=${dtcps_enable:-"NO"}		# Enable dtcps
#dtcps_program="${prefix}/sbin/dtcps"		# Location of dtcps
dtcps_tunif=${dtcps_tunif:-""}			# tunnel interface
dtcps_prefix=${dtcps_prefix:-""}		# prefix for host tunnel type
dtcps_flags=${dtcps_flags:-""}			# Flags to dtcps program

# interface cloning example
#dtcps_tunif='gif70'

# static allocation example
#dtcps_unit_min=70
#dtcps_unit_max=79
#dtcps_tunif='gif7[0-9]'

# prefix for host tunnel type.
# YOU MUST CHANGE TO ASSIGN THIS WITHIN YOUR ADDRESS BLOCK.
#dtcps_prefix='3ffe:501:185b:8000::'

. %%RC_SUBR%%

name="dtcps"
rcvar=`set_rcvar`
command="${prefix}/sbin/${name}"
command_interpreter="%%RUBY%%"
pidfile="/var/run/${name}.pid"
start_precmd="dtcps_prestart"

dtcps_prestart() {
	if [ -n "${dtcps_unit_min}" -a -n "${dtcps_unit_max}" ]; then
		unit=${dtcps_unit_min}
		while [ ${unit} -le ${dtcps_unit_max} ]; do
			ifconfig gif${unit} create >/dev/null 2>&1
			unit=$((${unit}+1))
		done
	fi
}

load_rc_config $name
command_args="-i ${dtcps_tunif} ${dtcps_prefix}"
run_rc_command "$1"
