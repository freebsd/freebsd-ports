#!/bin/sh
# $Id$

# PROVIDE: snort
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown

# Add the following lines to /etc/rc.conf to enable snort:
# snort_enable (bool):		Set to YES to enable snort
# 				Default: NO
# snort_flags (str):		Extra flags passed to snort
#				Default: -Dq
# snort_interface (str):	Network interface to sniff
#				Default: "" 
# snort_conf (str):		Snort configuration file
#				Default: ${PREFIX}/etc/snort.conf
#

. %%RC_SUBR%%

name="snort"
rcvar=`set_rcvar`

command="%%PREFIX%%/bin/snort"

load_rc_config $name

[ -z "$snort_enable" ]    && snort_enable="NO"
[ -z "$snort_conf" ]      && snort_conf="%%PREFIX%%/etc/snort.conf"
[ -z "$snort_flags" ]     && snort_flags="-Dq"

[ -n "$snort_interface" ] && snort_flags="$snort_flags -i $snort_interface"
[ -n "$snort_conf" ]      && snort_flags="$snort_flags -c $snort_conf"

run_rc_command "$1"
