#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: est
# REQUIRE: abi
# BEFORE: securelevel
# KEYWORD: FreeBSD

# Define est_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/est
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
est_enable="NO"
est_verbose="NO"

. %%RC_SUBR%%

name="est"
rcvar=`set_rcvar`

start_cmd="est_start"
stop_cmd="est_stop"

load_rc_config $name

kmoddir="%%PREFIX%%/modules"

est_start () {
	/sbin/kldload ${kmoddir}/est.ko
	if checkyesno est_verbose; then
		sysctl hw.est_verbose=1
	fi
}

est_stop () {
	/sbin/kldunload $name
}

run_rc_command "$1"
