#!/bin/sh
#
# $NetBSD: pksd.sh,v 1.1.1.1 2000/07/27 16:10:24 jlam Exp $
#
# PROVIDE: pksd
# REQUIRE: DAEMON

name="pksd"
command=${1:-start}

case ${command} in
start)
	if [ ! -f @PREFIX@/etc/${name}.conf ]
	then
		exit 0
	else
		dbdir=`awk '/db_dir/ { print $2 }' < @PREFIX@/etc/${name}.conf`
	fi
	if [ ! -f ${dbdir}/keydb000 -a -x @PREFIX@/bin/pksclient ]
	then
		@PREFIX@/bin/pksclient ${dbdir} create
	fi
	if [ -x @PREFIX@/bin/${name} -a -x @PREFIX@/bin/pks-queue-run.sh ]
	then
		echo "Starting ${name}."
		@PREFIX@/bin/${name} @PREFIX@/etc/${name}.conf &
		sleep 5
		@PREFIX@/bin/pks-queue-run.sh @PREFIX@/etc/${name}.conf
	fi
	;;
stop)
	if [ ! -f @PREFIX@/etc/${name}.conf ]
	then
		exit 0
	else
		socket=`awk '/socket_name/ { print $2 }' < @PREFIX@/etc/${name}.conf`
	fi
	if [ -x @PREFIX@/bin/${name}ctl -a -S ${socket} ]
	then
		echo "Stopping ${name}."
		@PREFIX@/bin/${name}ctl ${socket} shutdown
	else
		echo "couldn't stop ${name}."
	fi
	;;
restart)
	( $0 stop )
	sleep 1
	$0 start
	;;
esac
exit 0
