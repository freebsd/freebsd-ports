#!/bin/sh

case "$1" in
start)
	[ -x /usr/local/sbin/vpnc ] && /usr/local/sbin/vpnc && echo -n ' vpnc'
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
