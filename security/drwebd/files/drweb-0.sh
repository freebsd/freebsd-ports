#!/bin/sh

case "$1" in
start)
	if [ -x %PREFIX%/drweb/drwebd ]; then
		rm -f %PREFIX%/drweb/run/drwebd.sock;
		%PREFIX%/drweb/drwebd -ini:%PREFIX%/drweb/drweb32.ini && \
		    echo -n ' drwebd';
	fi
	;;
stop)
	if [ -r %PREFIX%/drweb/run/drwebd.pid ]; then
		kill `cat  %PREFIX%/drweb/run/drwebd.pid` >/dev/null 2>& 1;
		echo -n ' drwebd';
	fi
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
