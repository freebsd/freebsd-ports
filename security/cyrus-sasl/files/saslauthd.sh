#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: saslauthd1
# REQUIRE: DAEMON
# BEFORE: mail imap
# KEYWORD: FreeBSD shutdown
#
# NOTE for FreeBSD 5.0+:
# If you want this script to start with the base rc scripts
# move saslauthd1.sh to /etc/rc.d/saslauthd1

prefix=%%PREFIX%%

# Define these saslauthd1_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/saslauthd1
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE 
#
saslauthd1_enable="%%ENABLE_SASLAUTHD%%"		# Enable saslauthd
#saslauthd1_program="${prefix}/sbin/saslauthd1"	# Location of saslauthd1
saslauthd1_flags="-a pam"			# Flags to saslauthd program

. %%RC_SUBR%%

name="saslauthd1"
rcvar=`set_rcvar`
command="${prefix}/sbin/${name}"
pidfile="/var/state/${name}/mux.pid"

load_rc_config $name
run_rc_command "$1"
