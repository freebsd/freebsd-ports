#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: spread
# REQUIRE: LOGIN
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable spread:
#
#spread_enable="YES"
#
# See spread(1) for flags
#

. %%RC_SUBR%%

name=spread
rcvar=`set_rcvar`

command="%%PREFIX%%/sbin/spread"
command_args=""
pidfile=/var/run/${name}.pid
required_files=%%PREFIX%%/etc/${name}.conf

# set defaults

spread_enable=${spread_enable:-"NO"}
spread_flags=${spread_flags:-""}

load_rc_config ${name}
run_rc_command "$1"
