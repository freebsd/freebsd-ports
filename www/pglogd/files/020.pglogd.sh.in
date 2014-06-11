#!/bin/sh
CONFIG=%%PREFIX%%/etc/pglogd.conf
PID=/var/run/pglogd.pid

case "$1" in
start)
	[ -r ${CONFIG} ] && [ -x %%PREFIX%%/bin/pglogd ] && %%PREFIX%%/bin/pglogd -s -c ${CONFIG}  > /dev/null && echo -n ' pglogd'
	;;
stop)
	[ -r ${PID} ] && kill `cat ${PID}` > /dev/null && echo -n ' pglogd'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
