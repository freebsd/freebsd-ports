#!/bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/mail/vbsfilter/files/Attic/vbsfilter.sh,v 1.1 2001-03-13 06:47:30 dinoex Exp $
# 
if ! test -x %%PREFIX%%/libexec/vbsfilter
then
#	exit 0
fi
case $1 in
start)
	rm -f /var/run/vbsfilter
	%%PREFIX%%/libexec/vbsfilter -p local:/var/run/vbsfilter &&
	echo -n ' vbsfilter'
	;;
stop)
	killall vbsfilter
	rm -f /var/run/vbsfilter
	;;
*)
	echo "Usage: $0: [ start | stop ]" 2>&1
	exit 65
	;;
esac
