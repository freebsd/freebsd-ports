#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: radmind
# REQUIRE: DAEMON
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable radmind:
#
#radmind_enable="YES"
#
# You may also override the default flags:
#
#radmind_flags="-D /var/radmind -m 5 -u 077 -Llocal7 -w 0"
#
# See radmind(8) for flags
#

. %%RC_SUBR%%

name=radmind
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/radmind
command_args=""
required_files=/var/radmind/config

# set defaults

radmind_enable=${radmind_enable:-"NO"}
radmind_flags=${radmind_flags:-"-D /var/radmind -m 5 -u 077 -Llocal7 -w 0"}

load_rc_config ${name}
run_rc_command "$1"
