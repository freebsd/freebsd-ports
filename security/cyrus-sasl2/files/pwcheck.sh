#!/bin/sh
#

PREFIX=/usr/local

case "$1" in

start)
	if [ -x ${PREFIX}/sbin/pwcheck ]
	then
		${PREFIX}/sbin/pwcheck & && echo -n " pwcheck"
	fi
	;;

stop)
	if [ -r /var/run/pwcheck.pid ]
	then
		kill `cat /var/run/pwcheck.pid` && echo -n " pwcheck"
	fi
	;;

*)
	echo "usage: $0 {start|stop}" 1>&2
	exit 64
	;;

esac

