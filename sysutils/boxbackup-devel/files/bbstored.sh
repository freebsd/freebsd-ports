#!/bin/sh
#
#
# PROVIDE: bbstored
# REQUIRE: NETWORKING
# KEYWORD: FreeBSD shutdown

#
# Add the following line to /etc/rc.conf to enable bbstored:
#
#bbstored_enable="YES"
#

bbstored_enable=${bbstored_enable-"NO"}
bbstored_flags=${bbstored_flags-"/usr/local/etc/box/bbstored.conf"}
bbstored_pidfile=${bbstored_pidfile-"/var/run/bbstored.pid"}

. /etc/rc.subr

name="bbstored"
rcvar=`set_rcvar`
command="/usr/local/bin/bbstored"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
