#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

NULLMAILUSER=nullmail

PIDFILE=/var/run/nullmailer.pid
AWK=/usr/bin/awk
CAT=/bin/cat
GREP=/usr/bin/grep
PS=/bin/ps
RM=/bin/rm
LOGGER=/usr/bin/logger
KILL=/bin/kill
KILLALL=/usr/bin/killall

PRIORITY=local5.info
TAG=${NULLMAILUSER}

case "$1" in
start)
	echo -n ' nullmailer'
	if [ ! -r ${PIDFILE} ] ; then
		[ -x ${PREFIX}/sbin/nullmailer-send ] && su -l ${NULLMAILUSER} -c "${PREFIX}/sbin/nullmailer-send 2>&1 | ${LOGGER} -i -p ${PRIORITY} -t ${TAG} &" 
		JUNK=`${PS} -ax`
		PID=`${PS} awx | ${GREP} -v awk | ${AWK} '/nullmailer-send/ {print $1}'`
		echo $PID > ${PIDFILE}
	else
		echo ' already running'
	fi
	;;
stop)
	echo -n ' nullmailer'
	if [ -r ${PIDFILE} ] ; then
		${KILL} `${CAT} ${PIDFILE}` > /dev/null
		${RM} -f ${PIDFILE}
	fi
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
