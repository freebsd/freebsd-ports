#!/bin/sh
#
# $FreeBSD$
#
# PROVIDE: openupsd
# REQUIRE: LOGIN
# KEYWORD: FreeBSD shutdown

openupsd_enable=${openupsd_enable:-"NO"}

. %%RC_SUBR%%

name="openupsd"
rcvar=`set_rcvar`

start_cmd="${name}_start"
stop_cmd="${name}_stop"

openupsd_start()
{
	%%PREFIX%%/sbin/openupsd
}

openupsd_stop()
{
	killall openupsd
}

load_rc_config $name
run_rc_command "$1"
