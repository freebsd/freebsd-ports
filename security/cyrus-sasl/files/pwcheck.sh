#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: cyrus_pwcheck
# REQUIRE: DAEMON
# BEFORE: mail imap
# KEYWORD: FreeBSD shutdown
#

prefix=%%PREFIX%%

# Define these cyrus_pwcheck_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/cyrus_pwcheck
#
# DO NOT CHANGE THE DEFAULT VALUES HERE

cyrus_pwcheck_enable=${cyrus_pwcheck_enable:-"%%ENABLE_PWCHECK%%"}

# pwcheck program to use (pwcheck/pwcheck_pam)
cyrus_pwcheck_program=${cyrus_pwcheck_program:-"${prefix}/sbin/%%PWCHECK%%"}

. %%RC_SUBR%%

name="cyrus_pwcheck"
rcvar=`set_rcvar`
command=${prefix}/sbin/%%PWCHECK%%
pidfile="/var/run/pwcheck.pid"

load_rc_config $name
run_rc_command "$1"
