#!/bin/sh

PIDFILE=/var/run/sfscd.pid

case "$1" in
start)
	[ -x %%PREFIX%%/sbin/sfscd ] && %%PREFIX%%/sbin/sfscd && echo -n ' sfscd'
	;;
stop)
	[ -r $PIDFILE ] && kill -TERM `cat $PIDFILE` && echo -n ' sfscd'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
