#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: pfspamd
# REQUIRE: NETWORKING
# BEFORE:  mail
# KEYWORD: shutdown

#
# Add the following lines to /etc/rc.conf to enable spamd:
# pfspamd_enable (bool):	Set to "NO" by default.
#				Set it to "YES" to enable spamd
# pfspamd_flags (str):		Set to "" by default.
#				Extra flags passed to start command.

. %%RC_SUBR%%

name="pfspamd"
rcvar=`set_rcvar`

command="%%PREFIX%%/libexec/spamd"
start_postcmd="pfspamd_postcmd"
restart_postcmd="pfspamd_postcmd"

[ -z "$pfspamd_enable" ]	&& pfspamd_enable="NO"
[ -z "$pfspamd_flags" ]		&& pfspamd_flags=""

load_rc_config $name

pfspamd_postcmd() 
{
	if [ -x %%PREFIX%%/sbin/spamd-setup ]; then
		%%PREFIX%%/sbin/spamd-setup
	fi
}

run_rc_command "$1"
