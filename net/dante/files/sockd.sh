#!/bin/sh

case "$1" in
start)
	[ -x /usr/local/sbin/sockd ] && /usr/local/sbin/sockd -D > /dev/null && echo -n ' sockd'
	;;
stop)
	[ -r /var/run/sockd.pid ] && kill `cat /var/run/sockd.pid` && echo -n ' sockd'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
