#!/bin/sh
#
# $FreeBSD$
#
# Start or stop upclient.
#

rc_file=${0##*/}
rc_arg=$1

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/${rc_file}\$"); then
        echo "${rc_file}: Cannot determine PREFIX." >&2
        echo "Please use the complete pathname." >&2
        exit 64
fi

program_dir=${PREFIX}/sbin
program_file=upclient
program_path=${program_dir}/${program_file}

config_dir=${PREFIX}/etc
config_file=${program_file}.conf
config_path=${config_dir}/${config_file}

pid_dir=/var/run
pid_file=${program_file}.pid
pid_path=${pid_dir}/${pid_file}

syslog_facility=daemon.err

case "$rc_arg" in
start)
        if [ ! -x ${program_path} ]; then
                logger -sp ${syslog_facility} -t ${program_file} \
                        "unable to start: ${program_path} is missing."
                exit 72
        fi
        if [ ! -f ${config_path} ]; then
                logger -sp ${syslog_facility} -t ${program_file} \
                        "unable to start: ${config_path} is missing."
                exit 72
        fi
	ws=" 	"
	if ! grep -qs "^[$ws]*AuthKey[$ws]*=" ${config_path}; then
		logger -sp ${syslog_facility} -t ${program_file} \
			"unable to start: AuthKey is missing from" \
			"${config_path}."
                exit 72
	fi
	if grep -qs "^[$ws]*AuthKey[$ws]*=[$ws]*<your_authkey>" ${config_path}
	then
		logger -sp ${syslog_facility} -t ${program_file} \
			"unable to start: AuthKey isn't configured in" \
			"${config_path}."
                exit 72
	fi
        ${program_path} &&
        echo -n " ${program_file}"
        ;;
stop)
        if [ -r ${pid_path} ]; then
                kill $(cat ${pid_path}) 2> /dev/null
        else
                killall ${program_file} 2> /dev/null
        fi
        ;;
restart)
        $0 stop
        $0 start
        ;;
status)
        ps -auxww | egrep ${program_file} | egrep -v "($0|egrep)"
        ;;
*)
        echo "usage: ${rc_file} {start|stop|restart|status}" >&2
        exit 64
        ;;
esac

exit 0
