#!/bin/sh

cd `dirname $0`
cd ../..
PREFIX=`pwd`

case $1 in
	start)	echo -n ' rtsp_proxy'
		RTSP_PROXY=${PREFIX}/sbin/rtsp_proxy
		CONFIG_FILE=${PREFIX}/etc/qts_proxy.conf
		PID_FILE=/var/run/rtsp_proxy.pid
		[ -x ${RTSP_PROXY} ] && ${RTSP_PROXY} -c ${CONFIG_FILE} > /dev/null & && echo $! > ${PID_FILE}
		;;
        stop)	if [ -f /var/run/rtsp_proxy.pid ]; then
			kill `cat /var/run/rtsp_proxy.pid`
			rm /var/run/rtsp_proxy.pid
		fi
		;;
esac

