#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
	if [ -x ${PREFIX}/sbin/RunCache -a -f ${PREFIX}/etc/squid/squid.conf ]; then
		(cd /tmp; ${PREFIX}/sbin/RunCache >/dev/null 2>&1 &) ; echo -n ' squid'
	fi
	;;
stop)
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
