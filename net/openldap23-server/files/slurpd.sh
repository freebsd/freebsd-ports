#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: slurpd
# REQUIRE: slapd
# BEFORE:
# KEYWORD: FreeBSD shutdown

# Add the following line to /etc/rc.conf to enable slurpd:
#
#slurpd_enable="YES"
#
# See slurpd(8) for more flags
#

. %%RC_SUBR%%

name=slurpd
rcvar=`set_rcvar`

command=%%PREFIX%%/libexec/slurpd
required_files=%%PREFIX%%/etc/openldap/slapd.conf


slurpd_enable="NO"
slurpd_args=

load_rc_config $name
run_rc_command "$1"
