#!/bin/sh

dir="CHANGETHIS"

case "$1" in
start)
	echo -n " proxyper" 
	su -m nobody -c "$dir/proxyper" 2>/dev/null >/dev/null &
	;;
stop)
	killall proxyper && echo -n " proxyper"
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
