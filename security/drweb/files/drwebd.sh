#!/bin/sh
#
# $FreeBSD$

drwebd='!!PREFIX!!/drwebd'

case "$1" in
start)
	if [ -x $drwebd ]; then
	    echo -n ' drwebd'
	    $drwebd
	    /bin/chmod 660 /var/run/drwebd.sock
	fi
	;;
stop)
	/usr/bin/killall drwebd
	/bin/rm -f /var/run/drwebd.sock
	echo -n ' drwebd'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
