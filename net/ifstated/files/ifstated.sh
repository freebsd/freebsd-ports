#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: ifstated
# REQUIRE: NETWORKING SERVERS
# BEFORE: DAEMON
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable ifstated:
# ifstated_enable (bool):     Set to "NO" by default.
#                             Set it to "YES" to enable ifstated
# ifstated_flags (str):       Set to "-f %%PREFIX%%/etc/ifstated.conf" by default.
#                             Extra flags passed to start command
#
. %%RC_SUBR%%

name="ifstated"
rcvar=`set_rcvar`

command="%%PREFIX%%/sbin/ifstated"

[ -z "$ifstated_enable" ]       && ifstated_enable="NO"
[ -z "$ifstated_flags" ]        && ifstated_flags="-f %%PREFIX%%/etc/ifstated.conf"

load_rc_config $name

run_rc_command "$1"

