#!/bin/sh

case $1 in
start)
	if [ -f __PREFIX__/etc/adzapper.conf ]; then
		__PREFIX__/sbin/adzapper \
			1>>/var/log/adzapper.log \
			2>>/var/log/adzapper.log &
		test $? -eq 0 && echo -n ' adzapper'
	fi
	;;
stop)
	killall adzapper && echo -n ' adzapper'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
