#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: pop3proxyd
# REQUIRE: LOGIN
# BEFORE: mail
# KEYWORD: FreeBSD shutdown

#
# Add the following line to /etc/rc.conf to enable pop3proxyd:
#
#pop3proxyd_enable="YES"
#

. %%RC_SUBR%%

name=pop3proxyd
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/pop3proxyd

load_rc_config $name
run_rc_command "$1"
