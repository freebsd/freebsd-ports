#!/bin/sh
#
# $FreeBSD$
#
# PROVIDE: dnetc
# REQUIRE: LOGIN
# KEYWORD: FreeBSD shutdown

dnetc_enable=${dnetc_enable:-"NO"}

dir="%%BINDIR%%"
user="%%CLIENTUSER%%"

. %%RC_SUBR%%

name="dnetc"
rcvar=`set_rcvar`

required_files=${dir}/dnetc.ini

start_cmd="${name}_start"
stop_cmd="${name}_stop"

dnetc_start()
{
	echo -n " dnetc"
	su -m ${user} -c "${dir}/dnetc -quiet" 2>/dev/null >/dev/null
}

dnetc_stop()
{
	echo -n " dnetc"
	su -m ${user} -c "${dir}/dnetc -shutdown" 2>/dev/null >/dev/null
}

load_rc_config $name
run_rc_command "$1"
