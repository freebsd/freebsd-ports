#!/bin/sh

case "$1" in
start)
	if [ -x /usr/local/cyrus/bin/master -a \
	     -f /usr/local/etc/cyrus.conf -a \
	     -f /usr/local/etc/imapd.conf ]; then
		/usr/local/cyrus/bin/master &
		echo -n ' imapd'
	fi
	;;
stop)
	kill `ps -a | awk '/cyrus\/bin\/master$/ {print $1}'` && \
		echo -n ' imapd'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
