#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
	echo "$0: Cannot determine the PREFIX" >&2
	exit 1
fi

case "$1" in
start)
	[ -x ${PREFIX}/sbin/fhttpd ] && ${PREFIX}/sbin/fhttpd -c ${PREFIX}/etc/fhttpd.conf -l ${PREFIX}/share/fhttpd/fhttpd.log > /dev/null 2>&1 && echo -n ' fhttpd'
	;;
stop)
	killall fhttpd && echo -n ' fhttpd'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
