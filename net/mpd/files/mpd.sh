#!/bin/sh
# $FreeBSD$

DAEMON=/usr/local/sbin/mpd
PIDFILE=/var/run/mpd.pid

case "$1" in
start)
	if [ -f "${DAEMON}" -a -x "${DAEMON}" ]; then
		if [ -f "${PIDFILE}" ]; then
			echo ' mpd PID file found - not starting'
		else
			"${DAEMON}" -b -p "${PIDFILE}"
			echo -n ' mpd'
		fi
	else
		echo ' "${DAEMON}" executable not found - mpd not starting'
	fi
	;;
stop)
	if [ -f "${PIDFILE}" ]; then
		read -r pid junk < "${PIDFILE}"
		kill ${pid}
	else
		echo ' mpd PID file not found - not killing'
	fi
	;;
restart)
	$0 stop
	sleep 2
	$0 start
	;;
*)
	echo "usage: ${0##*/} {start|stop|restart}" >&2
	;;
esac

