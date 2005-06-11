#!/bin/sh
#
# $FreeBSD$
# 
if ! test -x %%PREFIX%%/libexec/sid-filter
then
	exit 0
fi
sid_filter_args="-t -r 0"
case "$1" in
start)
	sh "${0}" wait
	cd /var/crash
	rm -f /var/run/sid-filter.pid /var/run/sid-filter
	%%PREFIX%%/libexec/sid-filter -l -p local:/var/run/sid-filter \
		-P /var/run/sid-filter.pid ${sid_filter_args}
	echo -n ' sid-filter'
	;;
stop)
	if test -r /var/run/sid-filter.pid
	then
		kill `head -1 /var/run/sid-filter.pid`
	else
		echo " sid-filter: not running" 2>&1
	fi
	sh "${0}" wait
	rm -f /var/run/sid-filter.pid
	;;
wait)
	while ps -ax -o command | grep ^%%PREFIX%%/libexec/sid-filter
	do
		echo "please wait"
		sleep 1
	done
	;;
reload)
	if test -r /var/run/sid-filter.pid
	then
		kill -USR1 `head -1 /var/run/sid-filter.pid`
	else
		echo " sid-filter: not running" 2>&1
	fi
	;;
restart)
	$0 stop
	$0 start
	;;
*)
	echo "Usage: ${0##*/}: { start | stop | reload | restart }" >&2
	exit 64
	;;
esac
