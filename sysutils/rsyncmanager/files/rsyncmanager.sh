#!/bin/sh
#
# PROVIDE: rsyncmanager
# REQUIRE: DAEMON
# KEYWORD: FreeBSD
#
# Add the following line to /etc/rc.conf to enable rsyncmanager:
# rsyncmanager_enable (bool):      Set to "NO" by default.
#                             Set it to "YES" to enable rsyncmanager
# rsyncmanager_flags (str):        Set to "-C -c %%PREFIX%%/etc/rsyncmanager.conf" by default.
#                             Extra flags passed to start command
#
. %%RC_SUBR%%

name="rsyncmanager"
rcvar=`set_rcvar`

command="%%PREFIX%%/bin/rsyncmanager.rb"
pidfile="/var/run/rsyncmanager.pid"
command_interpreter="%%RUBY_WITHOUT_SUFFIX%%"
required_files=%%PREFIX%%/etc/rsyncmanager.xml

[ -z "$rsyncmanager_enable" ]       && rsyncmanager_enable="NO"
[ -z "$rsyncmanager_flags" ]        && rsyncmanager_flags="-c %%PREFIX%%/etc/rsyncmanager.xml"

load_rc_config $name

sig_stop=-TERM

extra_commands="reload"
run_rc_command "$1"
