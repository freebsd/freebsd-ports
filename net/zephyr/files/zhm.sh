#!/bin/sh
PREFIX=${PREFIX-/usr/local}

case $1 in
start)
	if [ -x ${PREFIX}/sbin/zhm -a -f ${PREFIX}/etc/zephyr/server.list ] ; then
	     PATH=${PREFIX}/sbin:${PREFIX}/bin:$PATH ; export PATH
	     zhm `cat ${PREFIX}/etc/zephyr/server.list` && echo -n ' zhm'
	fi
	;;
stop)
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
