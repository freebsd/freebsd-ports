#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
	[ -x ${PREFIX}/sbin/xinetd ] && \
		${PREFIX}/sbin/xinetd -pid 2> /var/run/xinetd.pid && \
		echo -n ' xinetd'
	;;
stop)
	killall xinetd && echo -n ' xinetd'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
