#!/bin/sh

PIDFILE=/var/run/sfssd.pid

case "$1" in
start)
	[ -x %%PREFIX%%/sbin/sfssd ] && %%PREFIX%%/sbin/sfssd && echo -n ' sfssd'
	;;
stop)
	[ -r $PIDFILE ] && kill -TERM `cat $PIDFILE` && echo -n ' sfssd'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
