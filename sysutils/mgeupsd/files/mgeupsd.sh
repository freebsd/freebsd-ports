#!/bin/sh
if [ "X${1}" = "Xstart" ]
then
	/usr/local/sbin/mgeupsd -run /usr/local/sbin/powerhandler /dev/cuaa0
	echo -n ' mgeupsd'
elif [ "X${1}" = "Xstop" ]
then
	kill `cat /var/run/mgeupsd.pid`
	rm -f /var/run/mgeupsd.pid
	rm -f /var/run/powerstatus
	echo -n ' mgeupsd'
else
	echo "Usage: `basename $0` { start | stop }"
	exit 1
fi
