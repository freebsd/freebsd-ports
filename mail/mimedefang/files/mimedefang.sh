#!/bin/sh -
#
#	initialization/shutdown script for DrWeb daemon and DrWeb mail filter

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

# Sool directory
SPOOLDIR=/var/spool/MIMEDefang

# Limit number of concurrent filters to 10
MAX_SLAVES=10
MIN_SLAVES=2
BUSY_TIMEOUT=240
IDLE_TIMEOUT=3600

# Uncomment next line to log statistics
# STATS_LOG="-t ${SPOOLDIR}/md-stats"

# Uncomment next line to flush stats file after each write
# FLUSH_STATS=-u
# Comment next line out if you do not want multiplexor to log messages.
# DO_LOGGING=-l

RETVAL=0

MIMEDEFANG=${PREFIX}/bin/mimedefang
MULTIPLEX=${PREFIX}/bin/mimedefang-multiplexor

# MIMEDefang socket
SOCK=${SPOOLDIR}/mimedefang.sock

# MIMEDefang-multiplexor socket
MXSOCK=${SPOOLDIR}/mdefang-mx.sock

# PID file location
PIDFILE=${SPOOLDIR}/mimedefang.pid

# MIMEDefang owner
USER=mailnull

[ -x $MIMEDEFANG ] || exit 1
[ -x $MULTIPLEX  ] || exit 1

# See how we were called.
case "$1" in
  start)
	# Clean spool directory
	su -m ${USER} -c "rm -f ${PIDFILE} ${SOCK} ${MXSOCK}"
	# Start daemons.
	# Start multiplexor
	su -m ${USER} -c "$MULTIPLEX -x $MAX_SLAVES -m $MIN_SLAVES -b $BUSY_TIMEOUT -i $IDLE_TIMEOUT $DO_LOGGING $STATS_LOG $FLUSH_STATS -s ${MXSOCK}"
	RETVAL=$?
	[ $RETVAL -ne 0 ] && exit 1
	echo -n " mimedefang-multiplexor"

	su -m ${USER} -c "$MIMEDEFANG -m ${MXSOCK} -p ${SOCK} -P ${PIDFILE}"
	RETVAL=$?
	[ $RETVAL -ne 0 ] && exit 1
	echo -n " mimedefang"
	;;
  stop)
	# Stop daemons.
	kill `cat ${PIDFILE}`
	echo -n " mimedefang"
	kill `ps ax | grep mimedefang-multiplexor | grep -v grep | grep -v sh | awk '{print $1}'`
	su -m ${USER} -c "rm -f ${PIDFILE} ${SOCK} ${MXSOCK}"
	echo -n " mimedefang-multiplexor"
	;;
	restart)
		$0 stop
		sleep 5
		$0 start
		;;
	*)
		echo "usage: `basename $0` {start|stop|restart}" >&2
		;;
esac
