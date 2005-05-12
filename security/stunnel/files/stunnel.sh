#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: stunnel
# REQUIRE: NETWORKING SERVERS
# BEFORE: DAEMON
# KEYWORD: shutdown

#
# Add some of the following variables to /etc/rc.conf to configure stunnel:
# stunnel_enable (bool):	Set to "NO" by default.
#				Set it to "YES" to enable stunnel.
# stunnel_config (str):		Default "!!PREFIX!!/etc/stunnel/stunnel.conf"
#				Set it to the full path to the config file
#				that stunnel will use during the automated
#				start-up.
# stunnel_pidfile (str):	Default "!!PREFIX!!/var/stunnel/stunnel.pid"
#				Set it to the value of 'pidfile' in
#				the stunnel.conf file.
#

. !!RC_SUBR!!

name="stunnel"
rcvar=`set_rcvar`
stunnel_config="!!PREFIX!!/etc/stunnel/${name}.conf"
stunnel_pidfile="/var/run/${name}.pid"
command="!!PREFIX!!/sbin/stunnel"

[ -z "$stunnel_enable" ]		&& stunnel_enable="NO"

load_rc_config $name

command_args=${stunnel_config}
pidfile=${stunnel_pidfile}

required_files="${stunnel_config}"

run_rc_command "$1"
