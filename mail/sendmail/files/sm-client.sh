#!/bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/mail/sendmail/files/Attic/sm-client.sh,v 1.2 2002-03-17 18:00:07 dinoex Exp $
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
	kill `head -1 /var/spool/clientmqueue/sm-client.pid`
	rm -f /var/spool/clientmqueue/sm-client.pid
	;;
*)
	echo "Usage: ${0##*/}: { start | stop }" 2>&1
	exit 65
	;;
esac
