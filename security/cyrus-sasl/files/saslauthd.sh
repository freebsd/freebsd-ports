#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: saslauthd1
# REQUIRE: DAEMON
# BEFORE: mail imap
# KEYWORD: FreeBSD shutdown
#
# NOTE for FreeBSD 5.0+:
# If you want this script to start with the base rc scripts
# move saslauthd1.sh to /etc/rc.d/saslauthd1

prefix=%%PREFIX%%

# Define these saslauthd1_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/saslauthd1
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE 
#
saslauthd1_enable="%%ENABLE_SASLAUTHD%%"		# Enable saslauthd
#saslauthd1_program="${prefix}/sbin/saslauthd1"	# Location of saslauthd1
saslauthd1_flags="-a pam"			# Flags to saslauthd program

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr

	name="saslauthd1"
	rcvar=`set_rcvar`
	command="${prefix}/sbin/${name}"
	pidfile="/var/state/${name}/mux.pid"

	load_rc_config $name
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

	if [ -n "${sasl_saslauthd1_enable}" ]; then
		echo "sasl_saslauthd1_enable has been depreciated, use saslauthd1_enable instead"
		saslauthd1_enable=$sasl_saslauthd1_enable
	fi

	if [ -z "${saslauthd1_program}" ]; then
		saslauthd1_program=${prefix}/sbin/saslauthd1
	fi

	if [ -n "${sasl_saslauthd1_flags}" ]; then
        	echo "sasl_saslauthd1_flags has been depreciated, use saslauthd1_flags instead"
        	saslauthd1_flags=$sasl_saslauthd1_flags
	fi

	rc=0

	case "${saslauthd1_enable}" in
	    [Yy][Ee][Ss])
		case "${1}" in

		    start)
			if [ -x ${saslauthd1_program} ] ; then
			    ${saslauthd1_program} ${saslauthd1_flags} \
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
fi
