#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

SMFILTER=${PREFIX}/sbin/sentinel
CONFIG=${PREFIX}/etc/sentinel.cf
SOCKET=${PREFIX}/var/sentinel/sentinel.socket

case "$1" in
start)
	if [ -x ${PREFIX}/sbin/sentinel -a -f ${PREFIX}/etc/sentinel.cf ]
	then
		rm -f ${SOCKET}
		${PREFIX}/sbin/sentinel -c ${PREFIX}/etc/sentinel.cf -p unix:${SOCKET} -d && echo -n ' sentinel'
	fi
	;;
stop)
		if [ -e ${SOCKET} ]
		then
			killall sentinel
		fi
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
