#!/bin/sh

case "$1" in
start)
	if [ -x %INSTALL%/drweb-smf ]; then
		killall drweb-smf >/dev/null 2>& 1;
		%INSTALL%/drweb-smf --conf=/usr/local/etc/drweb-sendmail/drweb_smf.conf && \
		    echo ' Starting  drweb-smf';
	fi
	;;
stop)
	killall drweb-smf >/dev/null 2>& 1;
	echo ' Stop drweb-smf';
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
