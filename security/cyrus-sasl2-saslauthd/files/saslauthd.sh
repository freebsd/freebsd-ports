#!/bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/security/cyrus-sasl2-saslauthd/files/Attic/saslauthd.sh,v 1.4 2004-03-31 16:32:17 ume Exp $
#

# PROVIDE: saslauthd
# REQUIRE: DAEMON
# BEFORE: mail imap
# KEYWORD: FreeBSD shutdown
#
# NOTE for FreeBSD 5.0+:
# If you want this script to start with the base rc scripts
# move saslauthd.sh to /etc/rc.d/saslauthd

prefix=%%PREFIX%%

# Define these saslauthd_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/saslauthd
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
saslauthd_enable=${saslauthd_enable:-"NO"}	# Enable saslauthd
saslauthd_flags=${saslauthd_flags:-"-a pam"}	# Flags to saslauthd program
#saslauthd_runpath="/var/state/saslauthd"	# Working directory
#saslauthd_program="${prefix}/sbin/saslauthd"	# Location of saslauthd

. %%RC_SUBR%%

name="saslauthd"
rcvar=`set_rcvar`
command="${prefix}/sbin/${name}"

load_rc_config $name

if [ -z "$saslauthd_runpath" ]; then
	pidfile="/var/state/${name}/${name}.pid"
	flags="${saslauthd_flags}"
else
	pidfile="${saslauthd_runpath}/${name}.pid"
	flags="${saslauthd_flags} -m ${saslauthd_runpath}"
fi

run_rc_command "$1"
