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

[ -z "$slurpd_enable" ] && slurpd_enable="NO"
[ -z "$slurpd_flags" ]  && slurpd_flags=

load_rc_config $name

if [ -n "$slurpd_args" ]; then
  warn "slurpd_args is deprecated, use slurpd_flags"
  slurpd_flags="$slurpd_args"
end

run_rc_command "$1"
