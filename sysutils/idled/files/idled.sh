#!/bin/sh
case "$1" in
	start)
		/usr/local/libexec/idled
		echo -n ' idled'
		;;
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
	*)
		/usr/local/libexec/idled
		echo -n ' idled'
		;;
esac
