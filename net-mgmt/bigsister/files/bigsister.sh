#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: bigsister
# REQUIRE: DAEMON
# BEFORE:  LOGIN
# KEYWORD: FreeBSD

. %%RC_SUBR%%

name="bigsister"
rcvar=`set_rcvar`
command="%%PREFIX%%/bigsister/bin/bb_start"

load_rc_config $name
run_rc_command "$1"
