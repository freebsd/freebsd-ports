#!/bin/sh

PREFIX=%%PREFIX%%
LIBDIR=${PREFIX}/lib/zaptel

case "$1" in
	start)
		/sbin/kldload ${LIBDIR}/zaptel.ko || exit 1
		/sbin/kldload ${LIBDIR}/qozap.ko || exit 1
		/sbin/kldload ${LIBDIR}/wcfxo.ko || exit 1
		/sbin/kldload ${LIBDIR}/wcfxs.ko || exit 1
		/sbin/kldload ${LIBDIR}/wct1xxp.ko || exit 1
		/sbin/kldload ${LIBDIR}/wct4xxp.ko || exit 1
		/sbin/kldload ${LIBDIR}/wcte11xp.ko || exit 1
		echo -n ${z}
		;;

	stop)
		/sbin/kldunload qozap.ko || exit 1
		/sbin/kldunload wcfxs.ko || exit 1
		/sbin/kldunload wcfxo.ko || exit 1
		/sbin/kldunload wct1xxp.ko || exit 1
		/sbin/kldunload wct4xxp.ko || exit 1
		/sbin/kldunload wcte11xp.ko || exit 1
		/sbin/kldunload zaptel.ko || exit 1
		echo -n " zaptel"
		;;

	*)
		echo ""
		echo "Usage: `basename $0` { start | stop }"
		echo ""
		exit 64
		;;
esac
