#!/bin/sh

# $FreeBSD$

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
	echo "$0: Cannot determine the PREFIX" >&2
	exit 1
fi

case $1 in
start)
	[ -x ${PREFIX}/sbin/blimitd ] &&
	echo -n ' blimitd' &&
	${PREFIX}/sbin/blimitd
	;;
stop)
	[ -f /var/run/blimitd.pid ] &&
	echo -n ' blimitd' &&
	kill `cat /var/run/blimitd.pid`
	;;
status)
	if [ -f /var/run/blimitd.pid ]; then
		ps -uxwwp `cat /var/run/blimitd.pid`
	else
		echo 'blimitd may not be running...possible processes below...'
		echo
		ps -auxww | egrep -e '^USER|blimitd' | egrep -v "($0|grep)"
	fi
    ;;
*)
    echo "usage: `basename $0` {start|stop|status}" >&2
    exit 64
    ;;
esac

exit 0
