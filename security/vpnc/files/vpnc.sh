#!/bin/sh

case "$1" in
start)
	[ -x /usr/local/sbin/vnpc ] && /usr/local/sbin/vnpc --pid-file /var/run/vpnc.pid > /dev/null && echo -n ' apache'
	;;
stop)
	#
	kill
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
