#!/bin/sh

# Start or stop jabberd
# $FreeBSD: /tmp/pcvs/ports/net/jabberd/files/Attic/jabberd.sh,v 1.3 2004-07-13 02:38:15 edwin Exp $

# PROVIDE: jabberd
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown
#
prefix=/usr/local

# Define these jabberd_* variables in one of these files:
#       /etc/rc.conf
#       /etc/rc.conf.local
#       /etc/rc.conf.d/gkrellmd
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
jabberd_chdir="/var/jabberd/pid"
jabberd_enable="NO"
jabberd_flags=""
jabberd_user="jabber"

. /etc/rc.subr

name="jabberd"
rcvar=`set_rcvar`
command="/usr/local/bin/jabberd"
command_args="&"
procname="/usr/local/bin/router"

load_rc_config $name

pidfile="${jabberd_chdir}/router.pid"

case "$1" in
	stop)
		echo "Stopping Jabber2"
		killall -u ${jabberd_user} jabberd c2s resolver router s2s sm
		for file in c2s resolver router s2s sm; do
			rm -f ${jabberd_chdir}/$file.pid
		done
	;;
	*)
		run_rc_command "$1"
	;;
esac
