#!/bin/sh
# $FreeBSD$
#
# PROVIDE: dictd
# REQUIRE: DAEMON
# KEYWORD: FreeBSD
#
# Add the following line to /etc/rc.conf to enable dictd:
#
# dictd_enable="YES"
#

. %%RC_SUBR%%

name=dictd
rcvar=`set_rcvar`
command=%%PREFIX%%/sbin/dictd

load_rc_config $name
run_rc_command "$1"
