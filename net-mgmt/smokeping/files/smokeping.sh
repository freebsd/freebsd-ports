#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
        [ -r ${PREFIX}/smokeping/etc/config ] && ${PREFIX}/bin/smokeping > /dev/null && echo -n ' smokeping'
        ;;
restart)
        [ -r ${PREFIX}/smokeping/etc/config ] && ${PREFIX}/bin/smokeping --restart > /dev/null && echo -n ' smokeping'
        ;;
stop)
        [ -r /var/run/smokeping.pid ] && kill `cat /var/run/smokeping.pid` > /dev/null && echo -n ' smokeping'
        ;;
*)
        echo "Usage: `basename $0` {start|restart|stop}" >&2
        ;;
esac

exit 0
