#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
        start)
	        [ -x ${PREFIX}/sbin/nntpswitchd ] && \
        	[ -r ${PREFIX}/etc/nntpswitch/nntpswitch.conf ] && \
        	${PREFIX}/sbin/nntpswitchd 2>/dev/null && \
                        echo -n ' nntpswitchd'

	;;
	stop)
	kill `cat /var/run/nntpswitchd.pid` && echo -n ' nntpswitchd'
	;;
	*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac
