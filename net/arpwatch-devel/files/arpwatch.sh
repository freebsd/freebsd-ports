#!/bin/sh

prog=$(realpath $0) || exit 1
dir=${prog%/*}
PREFIX=${dir%/etc/rc.d}

if [ ."$dir" = ."$prog" -o ."$PREFIX" = ."$dir" ]
then
	echo "$0: Cannot determine the PREFIX" >&2
	exit 1
fi

case $1 in
start)
	if [ -x "$PREFIX"/sbin/arpwatch -a -d "$PREFIX"/arpwatch ]; then
		"$PREFIX"/sbin/arpwatch && echo -n ' arpwatch'
	fi
	;;
stop)
	killall arpwatch && echo -n ' arpwatch'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
