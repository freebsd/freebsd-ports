#!/bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/mail/sendmail/files/Attic/sm-client.sh,v 1.4 2003-12-04 03:24:09 dinoex Exp $
# 
if ! test -x %%PREFIX%%/sbin/sendmail
then
	exit 0
fi
case "$1" in
start)
	%%PREFIX%%/sbin/sendmail -L sm-msp-queue -Ac -q30m
	echo -n ' sm-msp-queue'
	;;
stop)
	if test -e /var/spool/clientmqueue/sm-client.pid
	then
		kill `head -1 /var/spool/clientmqueue/sm-client.pid`
		rm -f /var/spool/clientmqueue/sm-client.pid
	fi
	;;
restart)
	if test -e /var/spool/clientmqueue/sm-client.pid
	then
		kill -1 `head -1 /var/spool/clientmqueue/sm-client.pid`
	fi
	;;
*)
	echo "Usage: ${0##*/}: { start | stop | restart }" >&2
	exit 64
	;;
esac
