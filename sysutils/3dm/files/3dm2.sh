#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: %%NAME%%
# REQUIRE: NETWORKING SERVERS
# BEFORE: DAEMON
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable %%NAME%%:
# twdm2_enable="YES"
#

. "%%RC_SUBR%%" 

name=twdm2
rcvar=`set_rcvar`

start_precmd="twdm2_precmd"
command="%%PREFIX%%/sbin/3dm2"
required_files="%%PREFIX%%/etc/3dm2.conf"

twdm2_precmd()
{
	umask 077
}

# set default
twdm2_enable=${twdm2_enable:-"NO"}

load_rc_config $name
run_rc_command "$1"
