#!/bin/sh

case "$1" in
start)
	[ -x %%PREFIX%%/sbin/anubis ] && %%PREFIX%%/sbin/anubis > /dev/null && echo -n ' anubis'
	;;
stop)
	killall anubis
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
