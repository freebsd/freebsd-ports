#!/bin/sh

case "$1" in
start)
	if [ -x %%PREFIX%%/sbin/thttpd_wrapper ]; then
		%%PREFIX%%/sbin/thttpd_wrapper &
		echo -n ' thttpd'
	fi
	;;
stop)
	kill `cat /var/run/thttpd_wrapper.pid` && killall thttpd && echo -n ' thttpd'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
