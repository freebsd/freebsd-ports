#!/bin/sh
# $FreeBSD$

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
	echo "$0: Cannot determine the PREFIX" >&2
	exit 1
fi

WWW6TO4DIR=${PREFIX}/etc/www6to4


case $1 in
start)
	if [ -d ${WWW6TO4DIR} \
	     -a -x ${PREFIX}/sbin/www6to4 \
	     -a -f ${WWW6TO4DIR}/www6to4.conf ]; then
		: seems OK
	else
		echo >&2 "$0: missing files!"
		exit 1
	fi
	cd ${WWW6TO4DIR}
	su -m nobody -c "${PREFIX}/sbin/www6to4 &" \
	    >/dev/null \
	&& echo -n " www6to4" \
	|| echo " www6to4 FAILED TO START"
	;;
stop)
	killall www6to4 && echo -n " www6to4"
	;;
restart)
	$0 stop
	$0 start
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
