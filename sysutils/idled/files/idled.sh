#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: idled
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable idled:
#
#idled_enable="YES"
#
# See idled(8) for flags
#

. %%RC_SUBR%%

name=idled
rcvar=`set_rcvar`

command=%%PREFIX%%/libexec/idled
required_files=%%PREFIX%%/etc/idled.cf

# set defaults

idled_enable=${idled_enable:-"NO"}
idled_flags=${idled_flags:-""}

load_rc_config $name
run_rc_command "$1"
