#!/bin/sh
#
# $FreeBSD$
# 
if ! test -x %%PREFIX%%/libexec/noattach
then
	exit 0
fi
case "$1" in
start)
	rm -f /var/run/noattach.pid /var/run/noattach
	%%PREFIX%%/libexec/noattach -p local:/var/run/noattach &&
	echo -n ' noattach'
	;;
stop)
	if test -r /var/run/noattach.pid
	then
		kill `head -1 /var/run/noattach.pid`
	else
		echo " noattach: not running" 2>&1
	fi
	rm -f /var/run/noattach.pid
	;;
reload)
	if test -r /var/run/noattach.pid
	then
		kill -USR1 `head -1 /var/run/noattach.pid`
	else
		echo " noattach: not running" 2>&1
	fi
	;;
*)
	echo "Usage: ${0##*/}: { start | stop | reload }" >&2
	exit 64
	;;
esac
