#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: openntpd
# REQUIRE: DAEMON
# BEFORE:  LOGIN
# KEYWORD: FreeBSD nojail

. %%RC_SUBR%%

name=openntpd
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/ntpd
required_files=%%PREFIX%%/etc/ntpd.conf

# set default
openntpd_enable=${openntpd_enable:-"NO"}

load_rc_config $name
run_rc_command "$1"
