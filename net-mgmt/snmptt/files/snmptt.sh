#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: snmptt
# REQUIRE: LOGIN
# KEYWORD: FreeBSD

#
# Add the following lines to /etc/rc.conf to enable snmptt:
#
#snmptt_enable="YES"
#
# See snmptt documentation for flags.
#

. %%RC_SUBR%%

name=snmptt
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/${name}
command_args="--daemon"
pidfile=/var/run/${name}.pid
# XXX: Makes assumptions about the interpreter path and version. However,
# USE_PERL5 should guarantee that this path is valid. In any event, we
# don't sed-ify the #! operators.
procname=/usr/bin/perl
required_files=%%PREFIX%%/etc/${name}.ini

# set defaults

snmptt_enable=${snmptt_enable:-"NO"}
snmptt_flags=${snmptt_flags:-""}

stop_postcmd=stop_postcmd

stop_postcmd()
{
  rm -f $pidfile
}

load_rc_config ${name}
run_rc_command "$1"
