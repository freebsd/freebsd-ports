#!/bin/sh

case $1 in
start)
	if [ -x %%PREFIX%%/news/rc.news ] ; then
	    %%PREFIX%%/news/rc.news && echo -n ' diablo'
	fi
	;;
stop)
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
