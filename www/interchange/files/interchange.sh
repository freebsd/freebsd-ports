#!/bin/sh

RUNDIR=/var/run/interchange
LOGDIR=/var/log/interchange
ICUSER=$(cat %%PREFIX%%/interchange/_uid)
PIDFILE=${RUNDIR}/interchange.pid
SOCKFILE=${RUNDIR}/interchange.sock

OPTS="SocketFile=${SOCKFILE} IPCsocket=${SOCKFILE}.ipc PIDfile=${PIDFILE}"
OPTS="${OPTS} --pidfile=${PIDFILE} --log=${LOGDIR}/error.log --rundir=${RUNDIR}"

case "$1" in
start)
	[ -d ${RUNDIR} ] || \
		(mkdir ${RUNDIR} && chown ${ICUSER}:${ICUSER} ${RUNDIR})
	[ -d ${LOGDIR} ] || \
		(mkdir ${LOGDIR} && chown ${ICUSER}:${ICUSER} ${LOGDIR})

	if [ -x %%PREFIX%%/bin/interchange ]; then
		su -m ${ICUSER} \
			-c "%%PREFIX%%/bin/interchange ${OPTS} >/dev/null" && \
		echo -n ' interchange'
	fi
	;;
stop)
	if [ -r ${PIDFILE} ]; then
		kill $(cat ${PIDFILE}) && \
			echo -n ' interchange'
	fi
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

