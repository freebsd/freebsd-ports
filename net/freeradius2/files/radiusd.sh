#!/bin/sh

# RADIUSD_FLAGS='-xxyzsf -l stdout'
RADIUSD_FLAGS=

if [ -r /etc/defaults/rc.conf ]; then
	. /etc/defaults/rc.conf
	source_rc_confs
elif [ -r /etc/rc.conf ]; then
	. /etc/rc.conf
fi

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
	touch /var/run/radiusd.pid
	chown nobody:nobody /var/run/radiusd.pid

	"$PREFIX"/sbin/radiusd $RADIUSD_FLAGS && echo -n " radiusd"
	;;
stop)
	killall radiusd && echo -n ' radiusd'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
