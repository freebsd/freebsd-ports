#!/bin/sh

case $1 in
start)
	if [ -x /usr/local/sbin/arpwatch -a -d /usr/local/arpwatch ]; then
		/usr/local/sbin/arpwatch && echo -n ' arpwatch'
	fi
	;;
stop)
	killall arpwatch && echo -n ' arpwatch'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
