#!/bin/sh

case "$1" in
start)
	if [ -x %%PREFIX%%/sbin/dhttpd ]; then
		%%PREFIX%%/sbin/dhttpd && echo -n ' dhttpd'
	fi
	;;
stop)
	killall dhttpd && echo -n ' dhttpd'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
