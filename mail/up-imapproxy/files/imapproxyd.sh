#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: imapproxyd
# REQUIRE: LOGIN
# BEFORE: mail
# KEYWORD: FreeBSD shutdown

#
# Add the following line to /etc/rc.conf to enable imapproxyd:
#
#imapproxyd_enable="YES"
#

. %%RC_SUBR%%

name=imapproxyd
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/in.imapproxyd

load_rc_config $name
run_rc_command "$1"
