#!/bin/sh
#
# $FreeBSD$
#
# PROVIDE: vtunclient
# REQUIRE: DAEMON
# KEYWORD: FreeBSD
#
# Add the following line to /etc/rc.conf to enable vtunclient:
#
# vtunclient_enable="YES"
# vtunclient_flags="<session> <server address>"
#

vtunclient_enable=${vtunclient_enable:-"NO"}
vtunclient_flags=${vtunclient_flags:-""}

. %%RC_SUBR%%

name=vtunclient
rcvar=`set_rcvar`
required_files="%%PREFIX%%/etc/vtund.conf"

command=%%PREFIX%%/sbin/vtund

load_rc_config $name
run_rc_command "$1"
