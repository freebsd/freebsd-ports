#!/bin/sh

case $1 in
start)
	[ -x %%PREFIX%%/sbin/apinger ] && %%PREFIX%%/sbin/apinger && echo -n ' apinger'
	;;
restart)
	killall -HUP apinger && echo -n ' apinger'
	;;
stop)
	killall apinger && echo -n ' apinger'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
