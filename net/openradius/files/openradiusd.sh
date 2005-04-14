#!/bin/sh
#
# $FreeBSD$
#
# PROVIDE: radiusd
# REQUIRE: DAEMON
# KEYWORD: FreeBSD
#
# Add the following line to /etc/rc.conf to enable radiusd:
#
# radiusd_enable="YES"
#

radiusd_enable=${radiusd_enable-"NO"}
radiusd_flags=${radiusd_flags-"-o %%LOGFILE%%"}

. /etc/rc.subr

name=radiusd
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/${name}

load_rc_config ${name}
run_rc_command "$1"
