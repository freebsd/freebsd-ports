#!/bin/sh

# PROVIDE radiusd
# REQUIRE: NETWORKING SERVERS
# BEFORE: DAEMON
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable radiusd:
#
# radiusd_enable="YES"
#

. %%RC_SUBR%%

name=radiusd
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/radiusd
radiusd_config=${radiusd_config:-"%%PREFIX%%/etc/raddb/radiusd.conf"}
required_files=${radiusd_config}
pidfile=/var/run/radiusd/radiusd.pid

radiusd_enable=${radiusd_enable:-"NO"}

load_rc_config $name
run_rc_command "$1"
