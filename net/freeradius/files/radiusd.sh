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
	"$PREFIX"/sbin/radiusd $RADIUSD_FLAGS && echo -n " radiusd"
	;;
stop)
	if [ -f /var/run/radiusd/radiusd.pid ]; then
		kill `cat /var/run/radiusd/radiusd.pid` && echo -n ' radiusd'
	fi
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
