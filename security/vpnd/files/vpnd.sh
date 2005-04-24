#!/bin/sh
#
# PROVIDE: vpnd
# REQUIRE: NETWORKING SERVERS
# BEFORE: DAEMON
# KEYWORD: FreeBSD shutdown
# 
# Note:
# Set "vpnd_enable=yes" in either /etc/rc.conf, /etc/rc.conf.local or
# /etc/rc.conf.d/vpnd to make this script actually do something.
#
# Please see rc.conf(5) and rc(8) for further details.
#

vpnd_enable=${vpnd_enable:-"NO"}

. /etc/rc.subr

name=vpnd
command=/usr/local/sbin/vpnd
rcvar=`set_rcvar`
load_rc_config ${name}

run_rc_command "$1"
