#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
	[ -x ${PREFIX}/sbin/dovecot ] && \
		${PREFIX}/sbin/dovecot && echo -n ' dovecot'
	;;
stop)
	/usr/bin/killall dovecot && echo -n ' dovecot'
	;;
*)
	echo "Usage: `basename $0` { start | stop }" >&2
	;;
esac

exit 0
