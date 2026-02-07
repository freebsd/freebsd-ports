#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

ETHERNETDEV=ed0

case "$1" in
start)
	[ -x ${PREFIX}/sbin/tdetect ] && ${PREFIX}/sbin/tdetect $ETHERNETDEV && echo -n " tdetect"
	;;
stop)
	killall tdetect && echo -n " tdetect"
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
