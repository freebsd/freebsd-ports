#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

IFFILE=${PREFIX}/etc/gdomap_if
PIDFILE=/var/run/gdomap.pid
GNUSTEP_SYSTEM_ROOT=${PREFIX}/GNUstep/System

case "$1" in
start)
	if [ -e ${GNUSTEP_SYSTEM_ROOT}/Makefiles/GNUstep.sh ]; then
		. ${GNUSTEP_SYSTEM_ROOT}/Makefiles/GNUstep.sh
		if [ -x ${GNUSTEP_SYSTEM_ROOT}/Tools/gdomap ]; then
			rm -f ${PIDFILE}
			${GNUSTEP_SYSTEM_ROOT}/Tools/gdomap -a ${IFFILE} -I ${PIDFILE}
			echo -n ' GNUstep'
		fi
	fi
	;;
stop)
	[ -r ${PIDFILE} ] && kill $(cat ${PIDFILE}) && echo -n ' GNUstep'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
