#!/bin/sh

# start dnews if it's really there ... usually in /usr/local ...

case $1 in
start)
	[ -x /usr/local/dnews/dnews_start ] \
		&& /usr/local/dnews/dnews_start.sh > /dev/null 2>&1 &

	# dnews started successfully if exit status = 0

	if [ $? -eq 0 ]; then
		echo -n ' dnews'
	fi
	;;
stop)
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
