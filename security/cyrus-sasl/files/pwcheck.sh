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

prefix=%%PREFIX%%

# Define these cyrus_pwcheck_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/cyrus_pwcheck
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
cyrus_pwcheck_enable="%%ENABLE_PWCHECK%%"			# Enable pwcheck daemon
cyrus_pwcheck_program="${prefix}/sbin/%%PWCHECK%%"	# pwcheck program to use
							# (pwcheck/pwcheck_pam)

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr

	name="cyrus_pwcheck"
	rcvar=`set_rcvar`
	command=${prefix}/sbin/%%PWCHECK%%
	pidfile="/var/run/pwcheck.pid"

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

	rc=0

	case "${cyrus_pwcheck_enable}" in
	    [Yy][Ee][Ss])
		case "${1}" in

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
