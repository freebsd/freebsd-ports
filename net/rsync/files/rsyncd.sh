#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: rsyncd
# REQUIRE: LOGIN
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable rsyncd:
#
#rsyncd_enable="YES"
#
# See rsync(1) for flags
#

. %%RC_SUBR%%

name=rsyncd
rcvar=`set_rcvar`

command=%%PREFIX%%/bin/rsync
command_args="--daemon"
pidfile=/var/run/${name}.pid
required_files=%%PREFIX%%/etc/${name}.conf

# set defaults

rsyncd_enable=${rsyncd_enable:-"NO"}
rsyncd_flags=${rsyncd_flags:-""}

load_rc_config ${name}
run_rc_command "$1"
