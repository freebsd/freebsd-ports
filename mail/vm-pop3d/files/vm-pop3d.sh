#!/bin/sh

case "$1" in
start)
	[ -x %%PREFIX%%/sbin/vm-pop3d ] && %%PREFIX%%/sbin/vm-pop3d -d && echo -n " vm-pop3d"
	;;
stop)
	killall vm-pop3d && echo -n " vm-pop3d"
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
