#!/bin/sh
#
# $FreeBSD$
#

. %%RC_SUBR%%

name="quickml"
rcvar=`set_rcvar`

command="%%RUBY%%"
command_args="%%PREFIX%%/sbin/${name}"
pidfile="/var/run/${name}.pid"
required_files=%%PREFIX%%/etc/quickmlrc

load_rc_config $name

run_rc_command "$1"
