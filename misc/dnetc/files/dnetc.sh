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

required_files=${dir}/${name}.ini

start_cmd="${name}_start"
stop_cmd="${name}_stop"

dnetc_start()
{
	if ps -U${user} >/dev/null; then
		echo "${name} already running?"
	else
		su -m ${user} -c "${dir}/${name} -quiet" >/dev/null 2>&1
		echo -n " ${name}"
	fi
}

dnetc_stop()
{
	if ps -U${user} >/dev/null; then
		su -m ${user} -c "${dir}/${name} -shutdown" >/dev/null 2>&1
		echo -n " ${name}"
	else
		echo "${name} not running?"
	fi
}

load_rc_config $name
run_rc_command "$1"
