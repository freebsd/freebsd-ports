#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

user=p3scan
configfile=${PREFIX}/etc/p3scan.conf

case "$1" in
    start)
	    echo -n "P3Scan "
	    ${PREFIX}/sbin/p3scan --configfile=${configfile} || exit 1
	    ;;
    stop)
	    echo -n "Shutting down P3Scan"
	    kill `cat /var/run/p3scan/p3scan.pid 2>/dev/null` &>/dev/null || exit 1
	    ;;
    reload|restart)
	    $0 stop && sleep 1 &&  $0 start || exit 1
	    ;;
    *)
	    echo "Usage: $0 {start|stop|reload|restart}"
	    exit 1
esac

exit 0
