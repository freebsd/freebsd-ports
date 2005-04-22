#!/bin/sh
# $FreeBSD$

# PROVIDE: dracd
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown

# Define these dracd_* variables in one of these files:
#       /etc/rc.conf
#       /etc/rc.conf.local
#       /etc/rc.conf.d/dracd
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
dracd_enable=${dracd_enable-"NO"}

. %%RC_SUBR%%

name="dracd"
rcvar=`set_rcvar`
command="%%PREFIX%%/sbin/rpc.dracd"

load_rc_config $name
run_rc_command "$1"
