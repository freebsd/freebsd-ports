#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
	[ -x ${PREFIX}/sbin/thttpd_wrapper ] && ${PREFIX}/sbin/thttpd_wrapper & && echo -n ' thttpd'
	;;
stop)
	kill `cat /var/run/thttpd_wrapper.pid` && killall thttpd && echo -n ' thttpd'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
