#!/bin/sh

case "$1" in
	start)
		%%%PREFIX%%%/sbin/mydns -b
		;;
	stop)
		kill `cat /var/run/mydns.pid`
		;;
	*)
		echo ""
		echo "Usage: `basename $0` { start | stop }"
		echo ""
		exit 64
		;;
esac
