#!/bin/sh

case "$1" in
	start)
		if [ -x %PREFIX%/sbin/racoon ]; then
			%PREFIX%/sbin/racoon -f %PREFIX%/etc/racoon/racoon.conf && echo -n ' racoon'
		fi
	;;

	stop)
		/usr/bin/killall racoon && echo -n ' racoon'
	;;
	
	*)
		echo "Usage: `basename $0` { start | stop }"
		exit 64
	;;
esac
