#!/bin/sh

PREFIX=%%PREFIX%%

case "$1" in
start)
	if [ -x ${PREFIX}/sbin/squid -a -f ${PREFIX}/etc/squid/squid.conf ]; then
		(cd /${PREFIX}/squid/logs; ${PREFIX}/sbin/squid >/dev/null 2>&1 &) ; echo -n ' squid'
	fi
	;;
stop)
		${PREFIX}/sbin/squid -k shutdown 2>&1
		# Uncomment this if you'd like the system to (attempt to
		# wait for) squid to shut down cleanly
		#echo "Sleeping for 45 seconds to allow squid to shutdown.."
		#sleep 45 
	;;
restart)
		${PREFIX}/sbin/squid -k reconfigure
	;;
*)
	echo "Usage: `basename $0` {start|stop|restart}" >&2
	;;
esac

exit 0
