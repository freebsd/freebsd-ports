#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
	[ -x ${PREFIX}/sbin/rpc.dracd ] && ${PREFIX}/sbin/rpc.dracd && echo -n ' dracd'
	;;
stop)
	killall rpc.dracd >/dev/null 2>&1 && echo -n ' dracd'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
