#!/bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/mail/vbsfilter/files/Attic/vbsfilter.sh,v 1.4 2003-12-04 03:24:09 dinoex Exp $
# 
if ! test -x %%PREFIX%%/libexec/vbsfilter
then
	exit 0
fi
case "$1" in
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
	echo "Usage: ${0##*/}: { start | stop }" >&2
	exit 64
	;;
esac
