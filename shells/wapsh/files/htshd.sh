#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
	[ -x "${PREFIX}/sbin/htshd" -a -f "${PREFIX}/etc/wapsh/htshd.conf" ] && ${PREFIX}/sbin/htshd -f ${PREFIX}/etc/wapsh/htshd.conf > /dev/null && echo -n ' htshd'
	;;
stop)
	killall htshd && echo -n ' htshd'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
