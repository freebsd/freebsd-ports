#!/bin/sh

case $1 in
start)
	if [ -x XXXX/sbin/nqsdaemon ] ; then
	    XXXX/sbin/nqsdaemon > /var/log/nqs.log
	    echo -n ' nqs' 
	fi
	;;
stop)
	killall -KILL nqsdaemon netdaemon loaddaemon && echo -n ' nqs'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
