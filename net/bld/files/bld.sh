#!/bin/sh

# PROVIDE: bld
# REQUIRE: LOGIN
# BEFORE: mail
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable bld:
#
#bld_enable="YES"
#
# See bld(8) for flags
#

. %%RC_SUBR%%

name=bld
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/bld
required_dirs=/var/run/bld

# set defaults

bld_enable=${bld_enable:-"NO"}
bld_flags=${bld_flags:-"-u bld -g bld"}

load_rc_config $name
run_rc_command "$1"
