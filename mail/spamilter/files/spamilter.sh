#!/bin/sh
#
# $FreeBSD$
# 
if ! test -x %%PREFIX%%/bin/spamilter
then
	exit 0
fi
case "$1" in
start)
	rm -f /tmp/Spamilter.pid
	%%PREFIX%%/bin/spamilter &&
	echo -n ' spamilter'
	;;
stop)
	if test -r /tmp/Spamilter.pid
	then
		kill `head -1 /tmp/Spamilter.pid`
	else
		echo " spamilter: not running" 2>&1
	fi
	rm -f /tmp/Spamilter.pid
	;;
reload)
	if test -r /tmp/Spamilter.pid
	then
		kill -USR1 `head -1 /tmp/Spamilter.pid`
	else
		echo " spamilter: not running" 2>&1
	fi
	;;
*)
	echo "Usage: ${0##*/}: { start | stop | reload }" >&2
	exit 64
	;;
esac
