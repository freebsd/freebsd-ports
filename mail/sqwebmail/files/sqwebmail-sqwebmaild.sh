#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
	${PREFIX}/libexec/sqwebmail/sqwebmail/sqwebmaild start > /dev/null && echo -n ' sqwebmaild'
	;;
stop)
	${PREFIX}/libexec/sqwebmail/sqwebmail/sqwebmaild stop > /dev/null && echo -n ' sqwebmaild'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0

