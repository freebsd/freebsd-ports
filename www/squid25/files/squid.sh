#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

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
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
