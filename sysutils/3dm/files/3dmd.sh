#!/bin/sh

#
# $FreeBSD$
#

case "$1" in
start)
	echo -n " 3dmd"
	/usr/local/sbin/3dmd &
	;;
stop)
	killall 3dmd && echo -n " 3dmd"
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
