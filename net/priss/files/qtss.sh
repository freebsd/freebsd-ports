#!/bin/sh

cd `dirname $0`
cd ../..
PREFIX=`pwd`
QTSS_PROXY=${PREFIX}/sbin/QuickTimeStreamingServer

case $1 in
start)
	[ -x ${QTSS_PROXY} ] && ${QTSS_PROXY} && echo -n ' qtss'
	;;
stop)
	killall `basename ${QTSS_PROXY}` && echo -n ' qtss'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
