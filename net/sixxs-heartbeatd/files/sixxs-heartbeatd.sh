#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: sixxs-heartbeatd
# REQUIRE: NETWORKING
# KEYWORD: FreeBSD

#
# Add the following lines to /etc/rc.conf to enable sixxs-heartbeatd:
#
#sixxs_heartbeatd_enable="YES"
#

. %%RC_SUBR%%

name=sixxs_heartbeatd
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/sixxs-heartbeatd
command_args=%%PREFIX%%/etc/heartbeat.conf
required_files=%%PREFIX%%/etc/heartbeat.conf

# set default
sixxs_heartbeatd_enable=${sixxs_heartbeatd_enable:-"NO"}

load_rc_config ${name}
run_rc_command "$1"
