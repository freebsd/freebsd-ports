#!/bin/sh

# Start or stop gkrellmd
# $FreeBSD$

PREFIX=%%PREFIX%%

case "$1" in
start)
	if [ -x ${PREFIX}/bin/gkrellmd -a \
	     -f ${PREFIX}/etc/gkrellmd.conf ]; then
		${PREFIX}/bin/gkrellmd &
		echo -n ' gkrellmd'
	fi
	;;
stop)
	killall gkrellmd && echo -n ' gkrellmd'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
