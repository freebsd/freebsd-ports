#!/bin/sh

PREFIX=%%PREFIX%%
LIBDIR=${PREFIX}/lib/zaptel

case "$1" in
	start)
		/sbin/kldload ${LIBDIR}/zaptel.ko || exit 1
		/sbin/kldload ${LIBDIR}/wcfxo.ko || exit 1
		/sbin/kldload ${LIBDIR}/wcfxs.ko || exit 1
		if /usr/sbin/devinfo | /usr/bin/grep -q wcfxo
		then
			${PREFIX}/bin/ztcfg 2> /dev/null
		else
			if /usr/sbin/devinfo | /usr/bin/grep -q wcfxs
			then
				${PREFIX}/bin/ztcfg 2> /dev/null
			fi
		fi
		echo -n " zaptel"
		;;

	stop)
		/sbin/kldunload wcfxs.ko || exit 1
		/sbin/kldunload wcfxo.ko || exit 1
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
