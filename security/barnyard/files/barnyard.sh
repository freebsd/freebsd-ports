#!/bin/sh
# 

# PROVIDE: barnyard
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown

# Add the following lines to /etc/rc.conf to enable barnyard:
# barnyard_enable (bool):	Set to YES to enable barnyard
# 				Default: NO
# barnyard_flags (str):		Extra flags passed to barnyard
#				Default: -D
# barnyard_conf (str):		Barnyard configuration file
#				Default: ${PREFIX}/etc/barnyard.conf
#

. %%RC_SUBR%%

name="barnyard"
rcvar=`set_rcvar`

command="%%PREFIX%%/bin/barnyard"

load_rc_config $name

[ -z "$barnyard_enable" ]    && barnyard_enable="NO"
[ -z "$barnyard_conf" ]      && barnyard_conf="%%PREFIX%%/etc/barnyard.conf"
[ -z "$barnyard_flags" ]     && barnyard_flags="-D"

[ -n "$barnyard_conf" ]      && barnyard_flags="$barnyard_flags -c $barnyard_conf"

run_rc_command "$1"
