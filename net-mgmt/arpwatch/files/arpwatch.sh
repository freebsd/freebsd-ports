#!/bin/sh

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
	if [ ! -e "$PREFIX"/arpwatch/arp.dat ]; then
		if [ -e "$PREFIX"/arpwatch/arp.dat- ]; then
			cp "$PREFIX"/arpwatch/arp.dat- "$PREFIX"/arpwatch/arp.dat	
		else
			touch "$PREFIX"/arpwatch/arp.dat
		fi
	fi

	case ${arpwatch_interfaces} in
	'')
		if [ -x "$PREFIX"/sbin/arpwatch -a -d "$PREFIX"/arpwatch ]; then
			"$PREFIX"/sbin/arpwatch && echo -n ' arpwatch'
		else
			echo "Error: Cannot find $PREFIX/sbin/arpwatch" >&2
			exit 1
		fi
		;;
	*)
		for interface in ${arpwatch_interfaces}; do
			touch "$PREFIX"/arpwatch/arp.${interface}.dat
			"$PREFIX"/sbin/arpwatch -i "${interface}" -f arp.${interface}.dat && echo -n " arpwatch(${interface})"
		done
		;;
	esac
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
