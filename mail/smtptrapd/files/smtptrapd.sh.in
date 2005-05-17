#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: smtptrapd
# REQUIRE: LOGIN
# BEFORE: mail
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable smtptrapd:
#
#smtptrapd_enable="YES"
#
# Run smtptrapd -h for flags
#

. %%RC_SUBR%%

name=smtptrapd
rcvar=`set_rcvar`

command=%%PREFIX%%/bin/smtptrapd

smtptrapd_enable=${smtptrapd_enable:-"NO"}
smtptrapd_flags=${smtptrapd_flags:-"-c /var/run/smtptrapd-root"}

load_rc_config $name
run_rc_command "$1"
