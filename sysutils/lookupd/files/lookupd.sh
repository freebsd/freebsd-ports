#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: lookupd
# REQUIRE: mountcritlocal
# BEFORE: LOGIN
# KEYWORD: FreeBSD

#
# Add the following lines to /etc/rc.conf to enable lookupd:
#
# lookupd_enable="YES"
#
# See lookupd(8) for flags
#

. /etc/rc.subr

name=lookupd
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/lookupd

lookupd_enable=${lookupd_enable:-"NO"}
lookupd_pidfile=${lookupd_pidfile:-"/var/run/lookupd.pid"}
lookupd_flags=${lookupd_flags:-""}

load_rc_config $name
run_rc_command "$1"
