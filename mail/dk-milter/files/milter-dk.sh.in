#!/bin/sh
#
# $FreeBSD$
# 
if ! test -x %%PREFIX%%/libexec/dk-filter
then
	exit 0
fi
dk_filter_args="-d example.com -c nofws -H -m MSA -s /var/db/domainkeys/default.key.pem -S default"
case "$1" in
start)
	sh "${0}" wait
	rm -f /var/run/dk-filter.pid /var/run/dk-filter
	%%PREFIX%%/libexec/dk-filter -l -p local:/var/run/dk-filter \
		-P /var/run/dk-filter.pid ${dk_filter_args}
	echo -n ' dk-filter'
	;;
stop)
	if test -r /var/run/dk-filter.pid
	then
		kill `head -1 /var/run/dk-filter.pid`
	else
		echo " dk-filter: not running" 2>&1
	fi
	sh "${0}" wait
	rm -f /var/run/dk-filter.pid
	;;
wait)
	while ps -axw -o pid,command | egrep "^[0-9]+ %%PREFIX%%/libexec/dk-filter "
	do
		echo "please wait"
		sleep 1
	done
	;;
restart)
	"$0" stop
	"$0" start
	;;
status)
	if [ -z "$(ps -axw -o pid,command | egrep "^[0-9]+ %%PREFIX%%/libexec/dk-filter ")" ]
	then
		echo "FAILED dk-filter is not running!"
	else
		echo "OK dk-filter is running!"
	fi
	;;
*)
	echo "Usage: ${0##*/}: {start|stop|restart|status}" >&2
	exit 64
	;;
esac
