#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: interchange
# REQUIRE: NETWORKING SERVERS
# BEFORE: DAEMON
# KEYWORD: shutdown

#
# Add the following lines to /etc/rc.conf to enable Interchange:
# interchange_enable (bool):      Set to "NO" by default.
#                                 Set it to "YES" to enable Interchange
# interchange_config (str):       Default config file: 
#                                 /usr/local/interchange/interchange.cfg
# interchange_args (str):         Custom additional arguments to be passed
#                                 to interchange (default empty).
#


. /etc/rc.subr

name="interchange"
rcvar=`set_rcvar`

interchange_enable=${interchange_enable:-"NO"}
interchange_config=${interchange_config:-"/usr/local/interchange/interchange.cfg"}
interchange_args=${interchange_args:-""}

load_rc_config $name

interchange_user="interch"
pidfile="/var/run/interchange/interchange.pid"
command="/usr/local/bin/interchange"
command_interpreter="/usr/local/bin/perl"
command_args="--config=${interchange_config} ${interchange_args}"

stop_cmd="interchange_cmd --stop"
restart_cmd="interchange_cmd --restart"
reload_cmd="interchange_cmd --restart"

interchange_cmd()
{
    su -l ${interchange_user} -c "exec env PIDfile=${pidfile} ${command} ${command_args} $1"
}

run_rc_command "$1"

