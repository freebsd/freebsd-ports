#!/bin/sh
#
# $FreeBSD$
#

action=$1

PREFIX=%%PREFIX%%

# Suck in the configuration variables.
if [ -z "${source_rc_confs_defined}" ]; then
        if [ -r /etc/defaults/rc.conf ]; then
                . /etc/defaults/rc.conf
                source_rc_confs
        elif [ -r /etc/rc.conf ]; then
                . /etc/rc.conf
        fi
fi

# The following sasl_saslauthd_* variables may be defined in rc.conf
#
# 	sasl_saslauthd1_enable  - Set to YES to enable saslauthd
#				 Default: %%ENABLESASLAUTHD%%
#
#	sasl_saslauthd1_program - Path to saslauthd program
#				 Default: ${PREFIX}/sbin/saslauthd1
#
#	sasl_saslauthd1_flags   - Flags to saslauthd program
#				 Default: -a pam

if [ -z "${sasl_saslauthd1_enable}" ]; then
	sasl_saslauthd1_enable=%%ENABLESASLAUTHD%%
fi

if [ -z "${sasl_saslauthd1_program}" ]; then
	sasl_saslauthd1_program=${PREFIX}/sbin/saslauthd1
fi

if [ -z "${sasl_saslauthd1_flags}" ]; then
	sasl_saslauthd1_flags="-a pam"
fi

rc=0

case "${sasl_saslauthd1_enable}" in
    [Yy][Ee][Ss])
	case "${action}" in

	    start)
		if [ -x ${sasl_saslauthd1_program} ] ; then
		    ${sasl_saslauthd1_program} ${sasl_saslauthd1_flags} \
			&& echo -n " saslauthd1"
		fi
		;;

	    stop)
		if [ -r /var/state/saslauthd1/mux.pid ]; then
		    kill `cat /var/state/saslauthd1/mux.pid` && \
			echo -n " saslauthd1"
		    rm /var/state/saslauthd1/mux.pid
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
