#!/bin/sh

case "$1" in
start)
	[ -x %%PREFIX%%/sbin/silcd ] && %%PREFIX%%/sbin/silcd > /dev/null && echo -n ' silcd'
	;;
stop)
	[ -r /var/run/silcd.pid ] && /bin/kill `cat /var/run/silcd.pid` > /dev/null && echo -n ' silcd'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
