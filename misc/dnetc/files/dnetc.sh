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

extra_commands="flush fetch update"

flush_cmd="${name}_flush"
fetch_cmd="${name}_fetch"
update_cmd="${name}_update"

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

dnetc_flush()
{
	su -m ${user} -c "${dir}/${name} -flush" >/dev/null 2>&1
}

dnetc_fetch()
{
	su -m ${user} -c "${dir}/${name} -fetch" >/dev/null 2>&1
}

dnetc_update()
{
	su -m ${user} -c "${dir}/${name} -update" >/dev/null 2>&1
}

load_rc_config $name
run_rc_command "$1"
