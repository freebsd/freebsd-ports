#!/bin/sh
args='-bd -q30m'

case "$1" in
start)
	[ -x /usr/local/sbin/exim ] && /usr/local/sbin/exim $args && echo -n ' exim'
	;;
stop)
	killall exim && echo -n ' exim'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
