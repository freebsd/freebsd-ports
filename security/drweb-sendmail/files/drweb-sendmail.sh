#!/bin/sh

case "$1" in
start)
	if [ -x %PREFIX%/sbin/drweb-smf ]; then
		rm -f %PREFIX%/drweb/run/drweb-smf.sock;
		%PREFIX%/sbin/drweb-smf --conf=%PREFIX%/etc/drweb/drweb_smf.conf && \
		    echo -n ' drweb-smf';
	fi
	;;
stop)
	killall drweb-smf >/dev/null 2>& 1;
	echo -n ' drweb-smf';
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
