#!/bin/sh
#
#
# PROVIDE: bbackupd
# REQUIRE: NETWORKING
# KEYWORD: FreeBSD shutdown

#
# Add the following line to /etc/rc.conf to enable bbackupd:
#
#bbackupd_enable="YES"
#

bbackupd_enable=${bbackupd_enable-"NO"}
bbackupd_flags=${bbackupd_flags-"/usr/local/etc/box/bbackupd.conf"}
bbackupd_pidfile=${bbackupd_pidfile-"/var/run/bbackupd.pid"}

. /etc/rc.subr

name="bbackupd"
rcvar=`set_rcvar`
command="/usr/local/bin/bbackupd"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
