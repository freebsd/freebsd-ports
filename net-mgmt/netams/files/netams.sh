#!/bin/sh

case "$1" in

start)
	sleep 3;
        /bin/mkdir -p /var/run/netams
        if [ -x /usr/local/libexec/netams ]; then
		if [ -f /usr/local/etc/netams.conf ]; then
                	/usr/local/libexec/netams -lf /usr/local/etc/netams.conf >/dev/null && echo -n ' NetAMS'
        	fi
	fi
        ;;

stop)
        killall netams
	rmdir /var/run/netams
        ;;
*)
        echo "$0 start | stop"
        ;;

esac



