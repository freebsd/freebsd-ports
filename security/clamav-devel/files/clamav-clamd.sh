#!/bin/sh
PREFIX=%%PREFIX%%

case "$1" in
start)
	# remove old socket
	rm -f /tmp/clamd
	[ -x ${PREFIX}/sbin/clamd ] && ${PREFIX}/sbin/clamd > /dev/null && echo -n ' clamd'
	;;
stop)
	killall 'clamd' && echo -n ' clamd'
	;;
*)
	echo "Usage: ${0##*/} { start | stop }" >&2
	;;
esac

exit 0
