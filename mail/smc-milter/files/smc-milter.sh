#!/bin/sh

case "$1" in
	start)
		/usr/local/bin/smc-milter
		echo ' smc-milter'
		;;
	stop)
		if [ -f /var/run/smc-milter.pid ]; then
			kill `cat /var/run/smc-milter.pid`
			echo ' smc-milter'
		fi
		;;
	*)
		echo ""
		echo "Usage: `basename $0` { start | stop }"
		echo ""
		exit 64
		;;
esac
