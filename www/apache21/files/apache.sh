#!/bin/sh
PREFIX=@@PREFIX@@

case "$1" in
start)
	[ "@@SSL@@" = "ssl" -a -f "$PREFIX/etc/apache2/ssl.crt/server.crt" ] && SSL=ssl
	[ -x ${PREFIX}/sbin/apachectl ] && ${PREFIX}/sbin/apachectl start${SSL} > /dev/null && echo -n ' apache2'
	;;
stop)
	[ -r /var/run/httpd.pid ] && ${PREFIX}/sbin/apachectl stop > /dev/null && echo -n ' apache2'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
