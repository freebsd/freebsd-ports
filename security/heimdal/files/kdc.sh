#!/bin/sh

kdc=%%PREFIX%%/libexec/kdc

case "$1" in
start)
    if [ -x $kdc ]; then
        echo -n ' kdc'
        $kdc  &
    fi
    ;;
stop)
    if [ -f /var/run/kdc.pid ]; then
        kill -TERM `cat /var/run/kdc.pid`
        rm -f /var/run/kdc.pid
        echo -n ' kdc'
    fi
    ;;
restart)
    if [ -f /var/run/kdc.pid ]; then
        $0 stop
	sleep 2
    fi
    $0 start
    ;;
*)
    echo "Usage: `basename $0` {start|stop}" >&2
    exit 64
    ;;
esac

exit 0
