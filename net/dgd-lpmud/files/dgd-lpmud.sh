#!/bin/sh
# $FreeBSD$

DGD_CONF=%%PREFIX%%/etc/dgd-lpmud/lpmud.dgd
DGD_USER=mud
DGD=%%PREFIX%%/sbin/dgd
DGD_HNAME=%%PREFIX%%/bin/lpmud-hname
DGD_HNAME_PORT=6047
DGD_HNAME_PASSWD=HNAMEPASS
DGD_LOG=%%DATADIR%%/lpmud/log/lpmud.log
DGD_PID=/var/run/dgd-lpmud.pid

case "$1" in
	start)
		if [ -x "${DGD}" ]; then
			su ${DGD_USER} -c "${DGD_HNAME} ${DGD_HNAME_PORT} ${DGD_HNAME_PASSWD}" > /dev/null 2>&1 &
			sleep 1
			su ${DGD_USER} -c "${DGD} ${DGD_CONF}" >> "${DGD_LOG}" 2>&1 &
			echo $(($!+1)) > "${DGD_PID}"
			echo -n ' dgd-lpmud'
		fi
		;;
	stop)
		kill -TERM `cat "${DGD_PID}"` && rm -f "${DGD_PID}"
		killall -TERM lpmud-hname
		;;
	*)
		echo ""
		echo "Usage: `basename $0` { start | stop }"
		echo ""
		exit 64
		;;
esac
