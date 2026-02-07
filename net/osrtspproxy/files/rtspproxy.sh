#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
	[ -x ${PREFIX}/sbin/rtspproxy ] && ${PREFIX}/sbin/rtspproxy > /dev/null 2>&1 & echo -n ' rtspproxy'
	;;
stop)
	killall rtspproxy && echo -n ' rtspproxy'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
