#!/bin/sh

# Start or stop jabberd
# $FreeBSD: /tmp/pcvs/ports/net-im/jabberd/files/Attic/jabberd.sh,v 1.5 2004-07-29 20:56:33 pav Exp $

# PROVIDE: jabberd
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown
#
prefix=%%PREFIX%%

# Define these jabberd_* variables in one of these files:
#       /etc/rc.conf
#       /etc/rc.conf.local
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
jabberd_chdir=${jabberd_chdir-"/var/jabberd/pid"}
jabberd_enable=${jabberd_enable-"NO"}
jabberd_user=${jabberd_user-"jabber"}

. %%RC_SUBR%%

name="jabberd"
rcvar=`set_rcvar`
command="${prefix}/bin/jabberd"
command_args="&"
procname="${prefix}/bin/router"

load_rc_config $name

pidfile="${jabberd_chdir}/router.pid"

case "$1" in
	stop|faststop|onestop)
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
