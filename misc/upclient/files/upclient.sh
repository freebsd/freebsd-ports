#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

if [ -f  ${PREFIX}/etc/upclient.conf ]; then
	if grep -qs '^[ 	]*AuthKey[ 	]*=' ${PREFIX}/etc/upclient.conf; then
		if grep -qs '^[ 	]*AuthKey[ 	]*=[ 	]*<your_authkey>' ${PREFIX}/etc/upclient.conf; then
			echo "upclient: AuthKey not configured in ${PREFIX}/etc/upclient.conf -- aborted." >&2
			exit 1
		fi
	else
		echo "upclient: ${PREFIX}/etc/upclient.conf is out of date -- aborted." >&2
		exit 1
	fi
else
	echo "upclient: ${PREFIX}/etc/upclient.conf doesn't exist -- aborted." >&2
	exit 1
fi

case "$1" in
start)
	[ -x ${PREFIX}/sbin/upclient ] && ${PREFIX}/sbin/upclient > /dev/null && echo -n ' upclient'
	;;
stop)
	[ -r /var/run/upclient.pid ] && kill `cat /var/run/upclient.pid` > /dev/null && echo -n ' upclient'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
