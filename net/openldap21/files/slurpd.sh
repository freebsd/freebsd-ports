#!/bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/net/openldap21/files/Attic/slurpd.sh,v 1.1 2003-02-24 04:27:22 edwin Exp $
#

slurpd=@@PREFIX@@/libexec/slurpd
pidfile=/var/run/slurpd.pid

case "$1" in
start)
	if [ -x $slurpd ]; then
		echo -n ' slurpd'
		$slurpd &
		echo $! > $pidfile
	fi
	;;
stop)
	pids=`ps xa | awk '/slurpd/{ print $1 }'`
	for pid in $pids; do
		kill $pid
		echo -n " slurpd($pid)"
	done
    	;;
restart)
	$0 stop
	$0 start
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
