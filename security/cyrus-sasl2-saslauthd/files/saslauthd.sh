#!/bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/security/cyrus-sasl2-saslauthd/files/Attic/saslauthd.sh,v 1.2 2003-08-28 17:44:28 ume Exp $
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
saslauthd_enable="YES"				# Enable saslauthd
#saslauthd_program="${prefix}/sbin/saslauthd"	# Location of saslauthd
saslauthd_flags="-a pam"			# Flags to saslauthd program

. %%RC_SUBR%%

name="saslauthd"
rcvar=`set_rcvar`
command="${prefix}/sbin/${name}"
pidfile="/var/state/${name}/${name}.pid"

load_rc_config $name
run_rc_command "$1"
