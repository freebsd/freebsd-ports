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
	case ${darwin_streaming_server_enable} in
	[Yy][Ee][Ss])
		/usr/bin/nice -5 ${darwin_streaming_server_program:-${PREFIX}/sbin/DarwinStreamingServer} ${darwin_streaming_server_flags} && \
		echo -n ' DarwinStreamingServer'
		;;
	esac
	;;
stop)
	case ${darwin_streaming_server_enable} in
	[Yy][Ee][Ss])
		if [ -f /var/run/DarwinStreamingServer.pid ]; then
			/bin/kill `/bin/cat /var/run/DarwinStreamingServer.pid`
			echo -n ' DarwinStreamingServer'
		fi
		;;
	esac
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
