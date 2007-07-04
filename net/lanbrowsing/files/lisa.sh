#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: lisa
# REQUIRE: LOGIN
# KEYWORD: FreeBSD

lisa_enable="NO"
lisa_conffile="%%PREFIX%%/etc/lisarc"

. %%RC_SUBR%%

name="lisa"
rcvar=`set_rcvar`
command="%%PREFIX%%/bin/lisa"
command_args="-q -c ${lisa_conffile}"
required_files="${lisa_conffile}"

load_rc_config $name

run_rc_command "$1"
