#!/bin/sh
#
# $FreeBSD$
#
# PROVIDE: proxyper
# REQUIRE: LOGIN
# KEYWORD: shutdown

proxyper_enable=${proxyper_enable:-"NO"}

dir="%%BINDIR%%"
user="nobody"

. %%RC_SUBR%%

name="proxyper"
rcvar=`set_rcvar`

pidfile=${dir}/rc5desproxy.pid
required_files=${dir}/${name}.ini

proxyper_user=${user}

command=${dir}/${name}
command_args=">/dev/null 2>&1 &"

load_rc_config $name
run_rc_command "$1"
