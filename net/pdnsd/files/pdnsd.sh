#!/bin/sh

case $1 in
start)
	if [ -x /usr/local/sbin/pdnsd -a -f /usr/local/etc/pdnsd.conf ]; then
		/usr/local/sbin/pdnsd -d
		echo ' pdnsd'
	fi
	;;
stop)
	killall pdnsd && echo -n ' pdnsd'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
