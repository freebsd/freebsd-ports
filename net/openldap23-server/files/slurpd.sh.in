#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: slurpd
# REQUIRE: slapd
# BEFORE:
# KEYWORD: shutdown

# Add the following line to /etc/rc.conf to enable slurpd:
#
#slurpd_enable="YES"
#
# See slurpd(8) for more flags
#

. "%%RC_SUBR%%"

name="slurpd"
rcvar=`set_rcvar`

command="%%PREFIX%%/libexec/slurpd"
required_files="%%PREFIX%%/etc/openldap/slapd.conf"

# read settings, set defaults
load_rc_config $name
: ${slurpd_enable="NO"}
if [ -n "${slurpd_args+set}" ]; then
  warn "slurpd_args is deprecated, use slurpd_flags"
  : ${slurpd_flags="$slurpd_args"}
else
  : ${slurpd_flags=""}
fi

run_rc_command "$1"
