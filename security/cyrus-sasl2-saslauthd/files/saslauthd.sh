#!/bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/security/cyrus-sasl2-saslauthd/files/Attic/saslauthd.sh,v 1.1 2003-06-01 04:24:15 ume Exp $
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
# 	sasl_saslauthd_enable  - Set to YES to enable saslauthd
#				 Default: YES
#
#	sasl_saslauthd_program - Path to saslauthd program
#				 Default: ${PREFIX}/sbin/saslauthd
#
#	sasl_saslauthd_flags   - Flags to saslauthd program
#				 Default: -a pam

if [ -z "${sasl_saslauthd_enable}" ]; then
	sasl_saslauthd_enable="YES"
fi

if [ -z "${sasl_saslauthd_program}" ]; then
	sasl_saslauthd_program="${PREFIX}/sbin/saslauthd"
fi

if [ -z "${sasl_saslauthd_flags}" ]; then
	sasl_saslauthd_flags="-a pam"
fi

rc=0

case "${sasl_saslauthd_enable}" in
    [Yy][Ee][Ss])
	case "${action}" in

	    start)
		if [ -x ${sasl_saslauthd_program} ] ; then
		    ${sasl_saslauthd_program} ${sasl_saslauthd_flags} \
			&& echo -n " saslauthd"
		fi
		;;

	    stop)
		if [ -r /var/state/saslauthd/saslauthd.pid ]; then
		    kill `cat /var/state/saslauthd/saslauthd.pid` && \
			echo -n " saslauthd"
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
