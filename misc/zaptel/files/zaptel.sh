#!/bin/sh

PREFIX=%%PREFIX%%
LIBDIR=${PREFIX}/lib/zaptel

case "$1" in
	start)
		/sbin/kldload ${LIBDIR}/zaptel.ko || exit 1
		/sbin/kldload ${LIBDIR}/wcfxo.ko || exit 1
		/sbin/kldload ${LIBDIR}/wcfxs.ko || exit 1
		if [ ! -d /dev/zap ]
		then
			mkdir -p /dev/zap || exit 1
		fi
		if [ ! -c /dev/zap/channel ]
		then
			/sbin/mknod /dev/zap/channel c 196 254 || exit 1
		fi
		if [ ! -c /dev/zap/ctl ]
		then
			/sbin/mknod /dev/zap/ctl c 196 0 || exit 1
		fi
		if [ ! -c /dev/zap/pseudo ]
		then
			/sbin/mknod /dev/zap/pseudo c 196 255 || exit 1
		fi
		if [ ! -c /dev/zap/timer ]
		then
			/sbin/mknod /dev/zap/timer c 196 253 || exit 1
		fi
		z=" zaptel"
		if /usr/sbin/pciconf -l | /usr/bin/grep -q ^wcfxo
		then
			for i in 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
			do
				if /usr/sbin/pciconf -l | /usr/bin/grep -q ^wcfxo${i}
				then
					if [ ! -c /dev/wcfxo${i} ]
					then
						/sbin/mknod /dev/wcfxo${i} c 197 ${i} || exit 1
					fi
				fi
			done
			${PREFIX}/bin/ztcfg 2> /dev/null
		else
			if /usr/sbin/pciconf -l | /usr/bin/grep -q ^wcfxs
			then
				for i in 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
				do
					if /usr/sbin/pciconf -l | /usr/bin/grep -q ^wcfxs${i}
					then
						if [ ! -c /dev/wcfxs${i} ]
						then
							/sbin/mknod /dev/wcfxo${i} c 198 ${i} || exit 1
						fi
					fi
				done
				${PREFIX}/bin/ztcfg 2> /dev/null
			else
				z=""
			fi
		fi
		echo -n ${z}
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
