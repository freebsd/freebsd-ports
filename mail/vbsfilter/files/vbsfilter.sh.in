#!/bin/sh
#
# $FreeBSD$
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
