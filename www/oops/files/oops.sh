#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
	if [ -x ${PREFIX}/sbin/oopsctl ]; then
		${PREFIX}/sbin/oopsctl start 2>&1 > /dev/null; echo -n ' oops'
	fi
	;;
stop)
	if [ -x ${PREFIX}/sbin/oopsctl ]; then
		${PREFIX}/sbin/oopsctl -s /tmp/oopsctl stop
	fi
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
