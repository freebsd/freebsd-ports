#!/bin/sh
#
# $FreeBSD$
#
# Start or stop BOINC
#

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
elif [ -f /usr/local/etc/rc.subr ]
then
	# FreeBSD 4.x
	. /usr/local/etc/rc.subr
fi

name="boinc"
rcvar=`set_rcvar`

boinc_user=%%BOINC_USER%%
boinc_home=%%BOINC_HOME%%
program_file=%%BOINC_BINARY%%
program_path=%%LOCALBASE%%/lib/boinc/${program_file}
syslog_facility=daemon.err

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
		echo "Starting BOINC client."
		export LD_LIBRARY_PATH=%%LOCALBASE%%/lib/boinc
		idprio 31 su - ${boinc_user} -c "${program_path} ${boinc_flags} >/dev/null &"
	fi
	;;

stop)
	killall ${program_file} 2> /dev/null
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

