#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
	[ -x ${PREFIX}/sbin/apachectl ] && ${PREFIX}/sbin/apachectl start > /dev/null && echo -n ' apache'
	;;
stop)
	[ -r /var/run/httpd.pid ] && ${PREFIX}/sbin/apachectl stop > /dev/null && echo -n ' apache'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
