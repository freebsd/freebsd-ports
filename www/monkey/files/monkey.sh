#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
	start)
	if [ -x ${PREFIX}/sbin/monkey ]; then
		${PREFIX}/sbin/monkey -D
		echo -n ' monkey'
	fi
	;;
	stop)
		kill `cat /var/run/monkey.pid`
		echo -n ' monkey'
	;;
	*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac
