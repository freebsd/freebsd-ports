#!/bin/sh

case "$1" in
'start')
	%%PREFIX%%/bin/3proxy %%PREFIX%%/etc/3proxy.cfg & echo -n "  3proxy"
	;;

'stop')
	/usr/bin/killall 3proxy
	;;

*)
	echo "Usage: ${0} { start | stop }"
	exit 1
	;;
esac
exit 0
