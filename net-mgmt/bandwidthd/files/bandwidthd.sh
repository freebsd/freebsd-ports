#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
        start)
	        [ -x ${PREFIX}/bandwidthd ] && \
        	[ -r ${PREFIX}/bandwidthd/etc/bandwidthd.conf ] && \
        	cd ${PREFIX}/bandwidthd && ./bandwidthd &&\
                        echo -n ' bandwidthd'

	;;
	stop)
	killall bandwidthd && echo -n ' bandwidthd'
	;;
	*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac
