#!/bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/net/boinc-client/files/Attic/boinc.sh-4.x,v 1.1 2004-12-15 05:14:36 edwin Exp $
#
# Start or stop BOINC
#

. /usr/local/etc/rc.subr

name="boinc"
rcvar=`set_rcvar`

boinc_user=%%BOINC_USER%%
boinc_home=%%BOINC_HOME%%
program_file=%%BOINC_BINARY%%
program_path=%%BOINC_DATADIR%%/client/${program_file}

[ -z "$boinc_enable" ] && boinc_enable="NO"

load_rc_config $name

case "$1" in
start)
	if checkyesno boinc_enable
	then
		if [ ! -x ${program_path} ]
		then
			logger -sp ${syslog_facility} -t ${program_file} \
				"unable to start: ${program_path} is missing."
			exit 72
		fi
		if ps axo ucomm | egrep ${program_file}; then
			logger -sp ${syslog_facility} -t ${program_file} \
			"unable to start: ${program_file} is already running."
			exit 72
		fi
		echo -n "BOINC "
		idprio 31 su - ${boinc_user} -c "${program_path} >/dev/null &"
	fi
	;;

stop)
	program=`expr ${program_file} : '^\(................\).*$'`
	killall ${program} 2> /dev/null
	;;

restart)
	$0 stop
	$0 start
	;;

status)
	ps auxww | egrep ${program_file} | egrep -v "($0|egrep)"
	;;

*)
	echo "usage: ${name} {start|stop|restart|status}" >&2
	exit 64
	;;
esac

