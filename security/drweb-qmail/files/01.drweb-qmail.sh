#!/bin/sh

case "$1" in
start)
	if [ -x %INSTALL%/qmail-queue.drweb ]; then
		killall qmail-queue.drweb >/dev/null 2>& 1;
		%INSTALL%/qmail-queue.drweb --conf=/usr/local/etc/drweb-qmail/drweb_qmail.conf && \
		    echo ' Starting  drweb-qmail';
	fi
	;;
stop)
	killall qmail-queue.drweb >/dev/null 2>& 1;
	echo ' Stop drweb-qmail';
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
