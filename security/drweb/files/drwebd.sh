#!/bin/sh
#
# $FreeBSD$

drwebd='!!PREFIX!!/drwebd'

case "$1" in
start)
	if [ -x $drwebd ]; then
	    echo -n ' drwebd'
	    $drwebd
	fi
	;;
stop)
	/usr/bin/killall drwebd
	rm -f /var/run/drwebd
	echo -n ' drwebd'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
