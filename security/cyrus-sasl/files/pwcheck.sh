#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: cyrus_pwcheck
# REQUIRE: DAEMON
# BEFORE: mail imap
# KEYWORD: FreeBSD shutdown
#
# NOTE for FreeBSD 5.0+:
# If you want this script to start with the base rc scripts
# move cyrus_pwcheck.sh to /etc/rc.d/cyrus_pwcheck

prefix=%%PREFIX%%

# Define these cyrus_pwcheck_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/cyrus_pwcheck
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
cyrus_pwcheck_enable="%%ENABLE_PWCHECK%%"			# Enable pwcheck daemon
cyrus_pwcheck_program="${prefix}/sbin/%%PWCHECK%%"	# pwcheck program to use
							# (pwcheck/pwcheck_pam)

. %%RC_SUBR%%

name="cyrus_pwcheck"
rcvar=`set_rcvar`
command=${prefix}/sbin/%%PWCHECK%%
pidfile="/var/run/pwcheck.pid"

load_rc_config $name
run_rc_command "$1"
