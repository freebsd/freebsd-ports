#!/bin/sh
# $FreeBSD$
#
# PROVIDE: nullmailer
# REQUIRE: DAEMON
#
# Add the following line to /etc/rc.conf to enable nullmailer:
#
# nullmailer_enable="YES"
#

. %%RC_SUBR%%

name=nullmailer
rcvar=`set_rcvar`
nullmailer_user=nullmail
command=%%PREFIX%%/sbin/nullmailer-send
command_args=" 2>&1 | /usr/bin/logger -i -p local5.info -t nullmail &"
load_rc_config $name
run_rc_command "$1"

