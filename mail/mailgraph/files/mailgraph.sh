#!/bin/sh

PREFIX=%%PREFIX%%

case "$1" in
start)
	/usr/bin/su www -c "cd ${PREFIX}/www/cgi-bin; ./mailgraph.pl -l /var/log/maillog" & > /dev/null 2>&1 && echo -n ' mailgraph'
	;;
stop)
	ps -U www | grep mailgraph | awk '{print $1}' | xargs kill && echo -n ' mailgraph'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
