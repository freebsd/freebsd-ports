#!/bin/sh

# Start or stop cyrus-imapd
# $FreeBSD$

case "$1" in
start)
	if [ -x /usr/local/cyrus/bin/master -a \
	     -f /usr/local/etc/cyrus.conf -a \
	     -f /usr/local/etc/imapd.conf ]; then
		/usr/local/cyrus/bin/master -d
		echo -n ' imapd'
	fi
	;;
stop)
	if [ -r /var/run/cyrus-master.pid ]; then
		kill `cat /var/run/cyrus-master.pid` && echo -n ' imapd'
		rm /var/run/cyrus-master.pid
	fi
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
