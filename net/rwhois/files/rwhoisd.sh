#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
	# remove or comment the following line and uncomment the one below it once you have
	# configured your server's data
	echo "rwhoisd not started; sample data still in place.   See ${PREFIX}/share/doc/rwhois for details."
	#if [ -x ${PREFIX}/lib/rwhois/sbin/rwhoisd ]; then (${PREFIX}/lib/rwhois/sbin/rwhoisd -c ${PREFIX}/lib/rwhois/rwhoisd.conf &); echo -n ' rwhoisd'; fi
	;;
stop)
	# killall rwhoisd && echo -n ' rwhoisd
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
