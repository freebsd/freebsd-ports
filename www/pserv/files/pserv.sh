#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/${0##*/}\$"); then
	echo "$0: Cannot determine the PREFIX" >&2
	exit 64
fi

case "$1" in
start)
	if [ -x ${PREFIX}/sbin/pserv ]; then
		${PREFIX}/sbin/pserv > /dev/null &
		echo -n ' pserv'
	fi
	;;
stop)
	killall pserv > /dev/null 2>&1
	echo -n ' pserv'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
