#!/bin/sh

case $1 in
start)
	if [ -x %%PREFIX%%/sbin/pdnsd -a -f %%PREFIX%%/etc/pdnsd.conf ]; then
		%%PREFIX%%/sbin/pdnsd -d
		echo -n ' pdnsd'
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
