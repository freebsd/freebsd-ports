#!/bin/sh
#
# $FreeBSD$

if ! prefix=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the prefix" >&2
    exit 1
fi
spread=${prefix}/sbin/spread
pidfile=/var/run/spread.pid
out=/var/log/spread.out
daemon=/usr/sbin/daemon

case "$1" in
start)
	if [ -x ${spread} ]; then
		echo -n ' spread'
		${daemon} -c ${spread} >${out} 2>&1 <&-
	fi
	;;
stop)
	if [ -f ${pidfile} ]; then
		kill `cat ${pidfile}`
		echo -n ' spread'
		rm ${pidfile}
	else
		echo ' spread: not running'
	fi
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
