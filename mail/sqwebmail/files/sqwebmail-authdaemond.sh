#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
	[ -r ${PREFIX}/share/sqwebmail/authdaemonrc ] && ${PREFIX}/libexec/sqwebmail/authlib/authdaemond start > /dev/null && echo -n ' authdaemond'
	;;
stop)
	${PREFIX}/libexec/sqwebmail/authlib/authdaemond stop > /dev/null && echo -n ' authdaemond'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0

