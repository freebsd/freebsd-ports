#!/bin/sh
#
# $FreeBSD$
# 
if ! test -x %%PREFIX%%/sbin/sendmail
then
	exit 0
fi
#
case "$1" in
start)
	# If there is a global system configuration file, suck it in.
	#
	if [ -r /etc/defaults/rc.conf ]; then
		. /etc/defaults/rc.conf
		source_rc_confs
	elif [ -r /etc/rc.conf ]; then
		. /etc/rc.conf
	fi

	# Flags to sendmail (as a server)
	sendmail_flags="${sendmail_flags--L sm-mta -bd -q30m}"
	# Flags for sendmail_msp_queue daemon.
	sendmail_msp_queue_flags="
		${sendmail_msp_queue_flags--L sm-msp-queue -Ac -q30m}"
	#
        %%PREFIX%%/sbin/sendmail ${sendmail_flags} &&
        echo -n ' sendmail'
        %%PREFIX%%/sbin/sendmail ${sendmail_msp_queue_flags} &&
        echo -n ' sm-msp-queue'
	;;
stop)
	if test -e /var/run/sendmail.pid
	then
		kill `head -1 /var/run/sendmail.pid`
		rm -f /var/run/sendmail.pid
	fi
	if test -e /var/spool/clientmqueue/sm-client.pid
	then
		kill `head -1 /var/spool/clientmqueue/sm-client.pid`
		rm -f /var/spool/clientmqueue/sm-client.pid
	fi
	;;
restart)
	if test -e /var/run/sendmail.pid
	then
		kill -1 `head -1 /var/run/sendmail.pid`
	fi
	if test -e /var/spool/clientmqueue/sm-client.pid
	then
		kill -1 `head -1 /var/spool/clientmqueue/sm-client.pid`
	fi
	;;
*)
	echo "Usage: ${0##*/}: { start | stop | restart }" >&2
	exit 64
	;;
esac
