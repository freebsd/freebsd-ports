#!/bin/sh
# File:		pop-before-smtp.sh
# Date:		Fri Mar  7 11:20:43 2003
# Time-stamp:	<2003-03-08 23:58:53 ericx>
# Description:	start/stop script for pop-before-smtp daemon
#
# $FreeBSD$

# Thanks to ume@FreeBSD.org for a nifty saslauthd.sh to steal from...

action=$1

PREFIX=%PREFIX%

# Suck in the configuration variables.
if [ -z "${source_rc_confs_defined}" ]; then
        if [ -r /etc/defaults/rc.conf ]; then
                . /etc/defaults/rc.conf
                source_rc_confs
        elif [ -r /etc/rc.conf ]; then
                . /etc/rc.conf
        fi
fi

# The following pop_before_smtp_* variables may be defined in rc.conf
#
# 	pop_before_smtp_enable  - Set to YES to enable pop-before-smtp
#				  Default: no
#
#	pop_before_smtp_program - Path to pop-before-smtp program
#				  Default: ${PREFIX}/sbin/pop-before-smtp
#
#	pop_before_smtp_config  - Path to pop-before-smtp configuration
#				  Default:
#				  ${PREFIX}/etc/pop-before-smtp-conf.pl
#
#	pop_before_smtp_flags   - Flags to pop-before-smtp program
#				  Default: [none]
#
#	pop_before_smtp_pid     - Path to pop-before-smtp pid file
#				  Default: /var/run/pop-before-smtp.pid
#

if [ -z "${pop_before_smtp_enable}" ]; then
	pop_before_smtp_enable=no
fi

if [ -z "${pop_before_smtp_program}" ]; then
	pop_before_smtp_program=${PREFIX}/sbin/pop-before-smtp
fi

if [ -z "${pop_before_smtp_config}" ]; then
	pop_before_smtp_config=${PREFIX}/etc/pop-before-smtp-conf.pl
fi

if [ -z "${pop_before_smtp_flags}" ]; then
	pop_before_smtp_flags=""
fi

if [ -z "${pop_before_smtp_pid}" ]; then
	pop_before_smtp_pid=/var/run/pop-before-smtp.pid
fi

rc=0

case "${pop_before_smtp_enable}" in
    [Yy][Ee][Ss])
	case "${action}" in

	    start)
		if [ -x ${pop_before_smtp_program} ] ; then
		    ${pop_before_smtp_program} \
		    --config=${pop_before_smtp_config} \
		    ${pop_before_smtp_flags} \
		    --daemon=${pop_before_smtp_pid} \
		    >/dev/null 2>&1 && \
		    echo -n " pop-before-smtp "
		fi
		;;

	    stop)
		if [ -r ${pop_before_smtp_pid} ]; then
		    kill `cat ${pop_before_smtp_pid}` && \
			echo -n " pop-before-smtp"
		    rm ${pop_before_smtp_pid}
		fi
		;;

	    *)
		echo "usage: $0 {start|stop}" 1>&2
		rc=64
		;;
	esac
	;;
    *)
	rc=0
	;;
esac

exit $rc
