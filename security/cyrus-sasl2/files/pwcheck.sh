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

# The following sasl_pwcheck_* variables may be defined in rc.conf
#
# 	sasl_pwcheck_enable  -	Set to YES to enable pwcheck
#				Default: %%ENABLEPWCHECK%%
#
#	sasl_pwcheck_program -	Path to pwcheck program (pwcheck/pwcheck_pam)
#				Default: ${PREFIX}/sbin/%%PWCHECK%%

if [ -z "${sasl_pwcheck_enable}" ] ; then
	sasl_pwcheck_enable=%%ENABLEPWCHECK%%
fi

if [ -z "${sasl_pwcheck_program}" ]; then
	sasl_pwcheck_program=${PREFIX}/sbin/%%PWCHECK%%
fi

rc=0

case "${sasl_pwcheck_enable}" in
    [Yy][Ee][Ss])
	case "${action}" in

	    start)
		if [ -x ${sasl_pwcheck_program} ] ; then
		    ${sasl_pwcheck_program} & && echo -n " pwcheck"
		fi
		;;

	    stop)
		if [ -r /var/run/pwcheck.pid ]; then
		    kill `cat /var/run/pwcheck.pid` && echo -n " pwcheck"
		    rm /var/run/pwcheck.pid
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
