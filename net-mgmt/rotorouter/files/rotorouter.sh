#!/bin/sh
#
# $Id$
#

# PROVIDE: rotorouter
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown
#
# Add the following line to /etc/rc.conf to enable rotorouter:
#
#   rotorouter_enable="YES"
#
# See rotorouter(8) for flags.
#

. %%RC_SUBR%%

name=rotorouter
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/${name}

# set defaults

rotorouter_enable=${rotorouter_enable:-"NO"}
rotorouter_flags="${rotorouter_flags:--h %%PREFIX%%/etc/rotorouter.conf}"

rotorouter_flags="${rotorouter_flags} &"

load_rc_config $name
run_rc_command "$1"

