#!/bin/sh

outgoing_queue_time=15m
mta=sendmail

case "$mta" in
	exim)
		program=/usr/local/sbin/exim

		if [ -f /usr/local/etc/exim/configure.in ]; then
			incoming_config=/usr/local/etc/exim/configure.in
		else
			incoming_config=/usr/local/etc/exim/configure
		fi

		outgoing_config=/usr/local/etc/exim/configure.out

		inpidfile=/var/run/exim_in.pid
		outpidfile=/var/run/exim_out.pid
		subpidfile=

		incoming_args="-C ${incoming_config} -oP ${inpidfile} -bd"
		outgoing_args="-C ${outgoing_config} -oP ${outpidfile} -q${outgoing_queue_time}"
		submitqueue_args=
		;;

	sendmail)
		program=/usr/sbin/sendmail

		incoming_queue=/var/spool/mqueue.in

		submit_queue_time=${outgoing_queue_time}

		inpidfile=/var/run/sendmail_in.pid
		outpidfile=/var/run/sendmail_out.pid
		subpidfile=/var/spool/clientmqueue/sm-client.pid

		incoming_args="-L sm-mta-in -bd \
				-OPrivacyOptions=noetrn \
				-OQueueDirectory=${incoming_queue} \
				-ODeliveryMode=queueonly \
				-OPidFile=${inpidfile}"
		outgoing_args="-L sm-mta-out -q${outgoing_queue_time} \
				-OPidFile=${outpidfile}"
		submitqueue_args="-L sm-msp-queue -Ac -q${submit_queue_time} \
				-OPidFile=${subpidfile}"
		;;

	*)
		echo "ERROR: I don't know the MTA '$mta'. Check your settings." >&2
		exit 2
		;;
esac

start_mta()
{
	echo -n " `basename ${program}`(incoming)"
	${program} ${incoming_args}

	echo -n " `basename ${program}`(outgoing)"
	${program} ${outgoing_args}
}

start_mspq ()
{
	if [ "${submitqueue_args}" ]; then
		echo -n " `basename ${program}`(submitqueue)"
		${program} ${submitqueue_args}
	fi
}

stop_mta()
{
	echo "Stopping `basename ${program}` (incoming)"
	kill -TERM `head -1 ${inpidfile}` 2>/dev/null

	echo "Stopping `basename ${program}` (outgoing)"
	kill -TERM `head -1 ${outpidfile}` 2>/dev/null
}

stop_mspq ()
{
	if [ "${submitqueue_args}" ]; then
		echo "Stopping `basename ${program}` (submitqueue)"
		kill -TERM `head -1 ${subpidfile}` 2>/dev/null
	fi
}


_action=${1:-start}

case ${_action} in
start)
        start_mta
	start_mspq
        ;;

stop)
        stop_mta
	stop_mspq
        ;;

restart)
	stop_mta
	stop_mspq
	sleep 5
	start_mta
	start_mspq
	;;

*)
	echo "Usage: `basename $0` {start|stop|restart}" >&2
	exit 64
	;;
esac
exit 0

