#!/bin/sh

case "$1" in
start)
	if [ -x %INSTALL%/drweb-postfix ]; then
		killall drweb-postfix >/dev/null 2>& 1;
		%INSTALL%/drweb-postfix --conf=/usr/local/etc/drweb-postfix/drweb_postfix.conf && \
		    echo ' Starting  drweb-postfix';
	fi
	;;
stop)
	killall drweb-postfix >/dev/null 2>& 1;
	echo ' Stop drweb-postfix';
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
