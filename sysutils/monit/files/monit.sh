#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: monit
# REQUIRE: NETWORKING SERVERS
# BEFORE: DAEMON
# KEYWORD: shutdown

#
# Add the following lines to /etc/rc.conf to enable monit:
# monit_enable (bool):        Set to "NO" by default.
#                             Set it to "YES" to enable monit
#
. %%RC_SUBR%%

name="monit"
rcvar=`set_rcvar`

restart_precmd="monit_checkconfig"
reload_precmd="monit_checkconfig"
stop_cmd="monit_stop"

default_config=%%PREFIX%%/etc/monitrc
required_files=${default_config}
command="%%PREFIX%%/bin/monit"
command_args="-c ${default_config}"
pidfile="/var/run/monit.pid"

[ -z "$monit_enable" ] && monit_enable="NO"

load_rc_config $name

monit_checkconfig()
{
  echo "Performing sanity check on monit configuration:"
  ${command} ${command_args} -t
}

monit_stop() {
        ${command} ${command_args} quit
        run_rc_command poll
}

extra_commands="reload"
run_rc_command "$1"
