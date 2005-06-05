#!/bin/sh
#
# $FreeBSD$
#
# Add the following lines to /etc/rc.conf to enable exilog agent:
#
#exilog_enable="YES"

. %%RC_SUBR%%

name=exilog
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/exilog_agent.pl
pidfile=/var/run/exilog.pid
required_files=%%PREFIX%%/etc/exilog.conf

# read settings, set default values
load_rc_config $name
: ${exilog_enable="NO"}

case $1 in
	stop)
		kill `cat $pidfile`
		rm -f $pidfile
	;;
	*)
		run_rc_command "$1"
	;;
esac
