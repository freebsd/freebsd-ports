#!/bin/sh

case "$1" in
start)
	[ -x %%PREFIX%%/sbin/apachectl ] && %%PREFIX%%/sbin/apachectl startssl > /dev/null && echo -n ' apache'
	;;
stop)
	[ -r /var/run/httpd.pid ] && %%PREFIX%%/sbin/apachectl stop > /dev/null && echo -n ' apache'
	;;
*)
	echo "Usage: ${0##*/} { start | stop }" >&2
	exit 64
	;;
esac

exit 0
