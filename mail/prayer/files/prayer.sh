#!/bin/sh
#
# $FreeBSD$
# 
if ! test -x %%PREFIX%%/prayer/sbin/prayer
then
	exit 0
fi
#
case "$1" in
start)
        %%PREFIX%%/prayer/sbin/prayer &&
        echo -n ' prayer'
	;;
stop)
	for i in \
		/var/spool/prayer/pid/prayer-session \
		/var/spool/prayer/pid/prayer
	do
		if test -e ${i}
		then
			kill `head -1 ${i}`
			rm -f "${i}"
		fi
	done
	killall prayer-session
	killall prayer
        echo -n ' prayer'
	;;
restart)
	$0 stop
	$0 start
	;;
*)
	echo "Usage: ${0##*/}: { start | stop | restart }" >&2
	exit 64
	;;
esac
