#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
	[ -x ${PREFIX}/sbin/tac_plus -a -f ${PREFIX}/etc/tac_plus/tac_plus.conf ] && ${PREFIX}/sbin/tac_plus -C ${PREFIX}/etc/tac_plus/tac_plus.conf -d 1 && echo -n ' tac_plus'
	;;
stop)
	killall tac_plus && echo -n ' tac_plus'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
