#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
        start)
	        [ -x ${PREFIX}/sbin/haproxy ] && \
        	[ -r ${PREFIX}/etc/haproxy.cfg ] && \
        	${PREFIX}/sbin/haproxy -f ${PREFIX}/etc/haproxy.cfg  && \
                        echo -n ' haproxy'

	;;
	stop)
	killall haproxy && echo -n ' haproxy'
	;;
	*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac
