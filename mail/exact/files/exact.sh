#!/bin/sh
PIDFILE=%%EXACTDIR%%/exact.pid

case "$1" in
	start)
		if [ -x %%PREFIX%%/sbin/exact ]; then
			%%PREFIX%%/sbin/exact && echo -n ' exact'
		fi
		;;
	stop)
		if [ -f ${PIDFILE} ]; then
			/bin/kill `cat ${PIDFILE}` > /dev/null 2>&1 && echo -n 'exact'
		else
			echo "exact isn't running"
		fi
		;;
	*)
		echo ""
		echo "Usage: `basename $0` { start | stop }"
		echo ""
		exit 64
		;;
esac
