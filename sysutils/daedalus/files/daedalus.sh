#!/bin/sh
#
# PROVIDE: daedalus
# REQUIRE: DAEMON
# KEYWORD: FreeBSD
#
# Add the following line to /etc/rc.conf to enable daedalus:
# daedalus_enable (bool):      Set to "NO" by default.
#                             Set it to "YES" to enable daedalus
# daedalus_flags (str):        Set to "-C -c %%PREFIX%%/etc/daedalus.conf" by default.
#                             Extra flags passed to start command
#
. %%RC_SUBR%%

name="daedalus"
rcvar=`set_rcvar`

command="%%PREFIX%%/bin/daedalus.rb"
pidfile="/var/run/daedalus.pid"
command_interpreter="%%RUBY_WITHOUT_SUFFIX%%"
required_files=%%PREFIX%%/etc/daedalus.conf

[ -z "$daedalus_enable" ]       && daedalus_enable="NO"
[ -z "$daedalus_flags" ]        && daedalus_flags="-C -c %%PREFIX%%/etc/daedalus.conf"

load_rc_config $name

sig_stop=-TERM

extra_commands="reload"
run_rc_command "$1"
