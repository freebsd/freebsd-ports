#!/bin/sh
PREFIX=__PREFIX__
ETCDIR=${PREFIX}/etc/dropbear
SBINDIR=${PREFIX}/sbin
BINDIR=${PREFIX}/bin
case "$1" in
start)
	[ -f ${ETCDIR}/dropbear_rsa_host_key ] || \
			${BINDIR}/dropbearkey -t rsa -f ${ETCDIR}/dropbear_rsa_host_key
	[ -f __PREFIX__/dropbear_dss_host_key ] || \
			${BINDIR}/dropbearkey -t dss -f ${ETCDIR}/dropbear_dss_host_key
	${SBINDIR}/dropbear
	echo $! > /var/run/dropbear.pid
	echo -n ' dropbear'
	;;
stop)
	if [ -f /var/run/dropbear.pid ]; then
		kill -TERM `cat /var/run/dropbear.pid`
		rm -f /var/run/dropbear.pid
		echo -n ' dropbear'
	fi
	;;
*)
	echo "Usage: ${0##*/}: { start | stop }" 2>&1
	exit 65
	;;
esac
