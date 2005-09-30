#!/bin/sh

# PROVIDE: rinetd
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable rinetd:
# rinetd_enable (bool): Set to "NO" by default.
#                       Set it to "YES" to enable rinetd
# rinetd_flags (str):   Set to "" by default.
#                       Extra flags passed to start command
#
. %%RC_SUBR%%

name="rinetd"
rcvar=`set_rcvar`

command="%%PREFIX%%/sbin/rinetd"
pidfile="/var/run/rinetd.pid"

[ -z "$rinetd_enable" ] && rinetd_enable="NO"
[ -z "$rinetd_flags" ]  && rinetd_flags=""

load_rc_config $name

run_rc_command "$1"
