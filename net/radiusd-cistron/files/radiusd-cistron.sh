#!/bin/sh
#
# $FreeBSD$
#
case "$1" in
start)
	[ -x %%PREFIX%%/sbin/radiusd ] &&
	%%PREFIX%%/sbin/radiusd -y &&
	echo -n ' radiusd'
        ;;
stop)
	if test -e /var/run/radiusd.pid
	then
		kill `head -1 /var/run/radiusd.pid`
		rm -f /var/run/radiusd.pid
	fi
	;;
*)
	echo ""
	echo "Usage: $0 { start | stop }"
	echo ""
	;;
esac
