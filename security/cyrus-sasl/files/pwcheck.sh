#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: cyrus_pwcheck
# REQUIRE: DAEMON
# BEFORE: mail imap
# KEYWORD: FreeBSD shutdown
#
# NOTE for FreeBSD 5.0+:
# If you want this script to start with the base rc scripts
# move cyrus_pwcheck.sh to /etc/rc.d/cyrus_pwcheck

# Define the following cyrus_pwcheck_* variables in one of the following:
#       /etc/rc.conf
#       /etc/rc.conf.d/pwcheck
#       ${prefix}/etc/rc.conf.d/pwcheck
#
#       cyrus_pwcheck_enable  - Set to YES to enable pwcheck
#				Default: %%ENABLE_PWCHECK%%
#
#       cyrus_pwcheck_program - Path to pwcheck program (pwcheck/pwcheck_pam)
#				Default: ${prefix}/sbin/%%PWCHECK%%

prefix=%%PREFIX%%

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr

	name="cyrus_pwcheck"
	rcvar=`set_rcvar`
	command=${prefix}/sbin/%%PWCHECK%%
	pidfile="/var/run/pwcheck.pid"

	# The below may be removed when load_local_rc_config is added to rc.subr
	
	if [ -f ${prefix}/etc/rc.conf.d/"$name" ]; then
        	debug "Sourcing ${prefix}/etc/rc.conf.d/${name}"
        	. ${prefix}/etc/rc.conf.d/"$name"
	fi

	load_rc_config $name

	if [ -z "${cyrus_pwcheck_enable}" ] ; then
        	cyrus_pwcheck_enable=%%ENABLE_PWCHECK%%
	fi

	# The above may be removed when load_local_rc_config is added to rc.subr
	#
	# load_local_rc_config $name
	run_rc_command "$1"
else
	# Suck in the configuration variables.
	if [ -z "${source_rc_confs_defined}" ]; then
		if [ -r /etc/defaults/rc.conf ]; then
			. /etc/defaults/rc.conf
			source_rc_confs
		elif [ -r /etc/rc.conf ]; then
			. /etc/rc.conf
		fi
	fi

	if [ -f ${prefix}/etc/rc.conf.d/cyrus_pwcheck" ]; then
		. ${prefix}/etc/rc.conf.d/cyrus_pwcheck}"
	fi

	if [ -z "${cyrus_pwcheck_enable}" ] ; then
		cyrus_pwcheck_enable=%%ENABLE_PWCHECK%%
	fi

	if [ -z "${cyrus_pwcheck_program}" ]; then
		cyrus_pwcheck_program=${prefix}/sbin/%%PWCHECK%%
	fi

	rc=0

	case "${cyrus_pwcheck_enable}" in
	    [Yy][Ee][Ss])
		case "${action}" in

		    start)
			if [ -x ${cyrus_pwcheck_program} ] ; then
			    ${cyrus_pwcheck_program} && echo -n " cyrus_pwcheck"
			fi
			;;

		    stop)
			if [ -r /var/run/pwcheck.pid ]; then
			    kill `cat /var/run/pwcheck.pid` && echo -n " cyrus_pwcheck"
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
fi
