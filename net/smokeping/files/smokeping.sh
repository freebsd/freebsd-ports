#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
        [ -r ${PREFIX}/etc/smokeping/config ] && \
	    su -f -m smokeping -c ${PREFIX}/bin/smokeping > /dev/null && \
	    echo -n ' smokeping'
        ;;
restart)
        [ -r ${PREFIX}/etc/smokeping/config ] && \
	    su -f -m smokeping -c "${PREFIX}/bin/smokeping --restart" > /dev/null && \
	    echo -n ' smokeping'
        ;;
stop)
        [ -r ${PREFIX}/var/smokeping/smokeping.pid ] && \
	    su -f -m smokeping -c "kill `cat ${PREFIX}/var/smokeping/smokeping.pid`" > /dev/null && \
	    echo -n ' smokeping'
        ;;
*)
        echo "Usage: `basename $0` {start|restart|stop}" >&2
        ;;
esac

exit 0
