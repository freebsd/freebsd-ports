#!/bin/sh

PATH=/bin:/usr/bin
export PATH

stop_hawk () {
	if [ -f /var/run/hawk.pid ];then
		kill `cat /var/run/hawk.pid`
	else
		ps -ax | awk '/[h]awk$/ {print $1}' | xargs kill
	fi
}

case "${1}" in
start)
	echo 'Starting hawk'
	%%PREFIX%%/sbin/hawk &
	;;
stop)
	echo 'Stopping hawk'
	stop_hawk
	;;
restart)
	echo 'Restarting hawk'
	stop_hawk
	%%PREFIX%%/sbin/hawk &
	;;
*)
	echo "Usage: $0 {start|stop|restart}"
	exit 1
	;;
esac

exit 0
