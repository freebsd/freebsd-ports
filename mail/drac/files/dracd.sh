#!/bin/sh

if ! PREFIX=$(/bin/expr $0 : "\(/.*\)/etc/rc\.d/${0##*/}\$"); then
	echo "$0: Cannot determine the PREFIX" >&2
	exit 64
fi

if [ -r /etc/defaults/rc.conf ]; then
	. /etc/defaults/rc.conf
	source_rc_confs
elif [ -r /etc/rc.conf ]; then
	. /etc/rc.conf
fi

case "$1" in
start)
	case ${dracd_enable:-NO} in
	[Yy][Ee][Ss])
		${dracd_program:-${PREFIX}/sbin/rpc.dracd} ${drac_flags} && echo -n ' dracd'
		;;
	esac
	;;
stop)
	case ${dracd_enable:-NO} in
	[Yy][Ee][Ss])
		/usr/bin/killall rpc.dracd >/dev/null 2>&1 && echo -n ' dracd'
	esac
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
