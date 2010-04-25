#!/bin/sh
# $FreeBSD: /tmp/pcvs/ports/net/dgd-kernel/files/dgd-kernel.sh,v 1.2 2010-04-25 07:18:12 glewis Exp $

DGD_CONF=%%PREFIX%%/etc/dgd-kernel/kernel.dgd
DGD_USER=mud
DGD=%%PREFIX%%/sbin/dgd
DGD_LOG=%%DATADIR%%/kernel.log
DGD_PID=/var/run/dgd-kernel.pid

case "$1" in
	start)
		if [ -x "${DGD}" ]; then
			su ${DGD_USER} -c "${DGD} ${DGD_CONF}" >> "${DGD_LOG}" 2>&1 &
			echo $(($!+2)) > "${DGD_PID}"
			echo -n ' dgd-kernel'
		fi
		;;
	stop)
		kill -TERM `cat "${DGD_PID}"` && rm -f "${DGD_PID}"
		;;
	*)
		echo ""
		echo "Usage: `basename $0` { start | stop }"
		echo ""
		exit 64
		;;
esac
