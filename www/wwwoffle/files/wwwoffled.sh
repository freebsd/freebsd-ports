#!/bin/sh

case $1 in
start)
	[ -x %PREFIX%/sbin/wwwoffled ] && \
		%PREFIX%/sbin/wwwoffled >/dev/null 2>&1 && echo -n ' wwwoffled'
	;;
stop)
	killall wwwoffled && echo -n ' wwwoffled'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
