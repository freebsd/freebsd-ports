#!/bin/sh
case "$1" in
	stop)
		killall -TERM idled
		echo "idled stopped"
		;;
	restart)
		killall -TERM idled
		/usr/local/libexec/idled
		echo "idled restarted"
		;;
	-h)
		echo "Usage: `basename $0` { start | stop | restart }"
		;;
	*)				# includes start
		/usr/local/libexec/idled
		echo -n ' idled'
		;;
esac
