#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/${0##*/}\$"); then
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
	case ${lmd_enable:-NO} in
	[Yy][Ee][Ss])
		[ -f ${PREFIX}/etc/lmd.conf ] && ${lmd_program:-${PREFIX}/sbin/lmd} ${lmd_flags} && echo -n ' lmd'
		;;
	esac
	;;
stop)
	case ${lmd_enable:-NO} in
	[Yy][Ee][Ss])
		[ -f ${PREFIX}/etc/lmd.conf ] && /usr/bin/killall lmd && echo -n ' lmd'
		;;
	esac
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
