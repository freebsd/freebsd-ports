#!/bin/sh
case "$1" in
start)
	__PREFIX__/sbin/sshd
	echo -n ' sshd'
	;;
stop)
	if [ -f /var/run/sshd.pid ]; then
		kill -TERM `cat /var/run/sshd.pid`
		rm -f /var/run/sshd.pid
		echo -n ' sshd'
	fi
	;;
restart)
	if [ -f /var/run/sshd.pid ]; then
		kill -HUP `cat /var/run/sshd.pid`
		echo 'sshd restarted'
	fi
	;;
*)
	echo "Usage: ${0##*/}: { start | stop | restart }" >&2
	exit 64
	;;
esac
