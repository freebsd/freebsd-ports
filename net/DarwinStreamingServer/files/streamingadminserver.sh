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
	case ${streamingadminserver_enable} in
	[Yy][Ee][Ss])
		${streamingadminserver_program:-${PREFIX}/sbin/streamingadminserver.pl} ${streamingadminserver_flags} && \
		echo -n ' StreamingAdminServer'
		;;
	esac
	;;
stop)
	case ${streamingadminserver_enable} in
	[Yy][Ee][Ss])
		if [ -f /var/run/streamingadminserver.pid ]; then
			/bin/kill `/bin/cat /var/run/streamingadminserver.pid`
			echo -n ' StreamingAdminServer'
		fi
		;;
	esac
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
