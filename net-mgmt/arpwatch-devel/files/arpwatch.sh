#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: arpwatch
# REQUIRE: NETWORKING SERVERS
# BEFORE: DAEMON
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable arpwatch:
# arpwatch_enable (bool):     Set to "NO" by default.
#                             Set it to "YES" to enable arpwatch
# arpwatch_flags (str):       Set to "-N" by default.
#                             Extra flags passed to start command
#
. %%RC_SUBR%%

name="arpwatch"
rcvar=`set_rcvar`

command="%%PREFIX%%/sbin/arpwatch"

[ -z "$arpwatch_enable" ]       && arpwatch_enable="NO"
[ -z "$arpwatch_flags" ]        && arpwatch_flags="-N"

load_rc_config $name

run_rc_command "$1"

