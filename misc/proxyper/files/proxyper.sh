#!/bin/sh
#
# $FreeBSD$
#
# PROVIDE: proxyper
# REQUIRE: LOGIN
# KEYWORD: FreeBSD shutdown

proxyper_enable=${proxyper_enable:-"NO"}

dir="%%BINDIR%%"

. %%RC_SUBR%%

name="proxyper"
rcvar=`set_rcvar`

required_files=${dir}/${name}.ini

start_cmd="${name}_start"
stop_cmd="${name}_stop"

proxyper_start()
{
	echo -n " proxyper" 
	su -m nobody -c "${dir}/proxyper" >/dev/null 2>&1 &
}

proxyper_stop()
{
	kill `cat ${dir}/rc5desproxy.pid`
	echo -n " proxyper" 
}

load_rc_config $name
run_rc_command "$1"
