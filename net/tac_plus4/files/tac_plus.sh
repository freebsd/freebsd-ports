#!/bin/sh
#
# $FreeBSD$
#
# PROVIDE: tac_plus
# REQUIRE: DAEMON
# KEYWORD: FreeBSD
#
# Add the following line to /etc/rc.conf to enable the TACACS+ daemon:
#
# tac_plus_enable="YES"
#

tac_plus_enable=${tac_plus_enable-"NO"}
tac_plus_flags=${tac_plus_flags-"-C %%PREFIX%%/etc/tac_plus.conf"}

. %%RC_SUBR%%

name=tac_plus
rcvar=`set_rcvar`

command="%%PREFIX%%/bin/tac_plus"
pidfile="/var/run/${name}.pid"

load_rc_config ${name}
run_rc_command "$1"
