#!/bin/sh
# $FreeBSD$

# PROVIDE: dansguardian
# REQUIRE: DAEMON squid
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown

# Define these dansguardian_* variables in one of these files:
#       /etc/rc.conf
#       /etc/rc.conf.local
#       /etc/rc.conf.d/dansguardian
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
dansguardian_enable=${dansguardian_enable:-"NO"}
dansguardian_flags=${dansguardian_flags:-""}
dansguardian_pidfile=${dansguardian_pidfile:-"/var/run/dansguardian.pid"

. %%RC_SUBR%%

name="dansguardian"
rcvar=`set_rcvar`
command="%%PREFIX%%/sbin/dansguardian"

load_rc_config $name

pidfile="${dansguardian_pidfile}"

run_rc_command "$1"

