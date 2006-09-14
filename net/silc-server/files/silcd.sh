#!/bin/sh
#
# $FreeBSD$
#
# PROVIDE: silcd
# REQUIRE: NETWORKING
#
# Add the following line to /etc/rc.conf[.local] to enable silcd:
#
# silcd_enable="YES"
#

silcd_enable=${silcd_enable-"NO"}

. %%RC_SUBR%%

name=silcd
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/${name}
pidfile=/var/run/${name}.pid

extra_commands="keygen"
keygen_cmd="silcd_keygen"
start_precmd="silcd_precmd"

silcd_keygen()
{
	umask 077
	${command} -C %%PREFIX%%/etc/silc
}

silcd_precmd()
{
	if [ ! -f %%PREFIX%%/etc/silc/silcd.prv -a ! -f %%PREFIX%%/etc/silc/silcd.pub ]; then
		run_rc_command keygen
	fi
}

load_rc_config ${name}
run_rc_command "$1"
