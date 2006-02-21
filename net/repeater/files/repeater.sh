#!/bin/sh

# PROVIDE: repeater
# REQUIRE: NETWORKING SERVERS
# BEFORE: DAEMON
# KEYWORD: shutdown

#
# Add the following lines to /etc/rc.conf to enable repeater:
#
# repeater_enable="YES"
#

. /etc/rc.subr

name=repeater
rcvar=`set_rcvar`

load_rc_config $name

repeater_enable=${repeater_enable:-"NO"}
repeater_server_port=${repeater_server_port:-5500}
repeater_viewer_port=${repeater_viewer_port:-5900}
repeater_log=${repeater_log:-"/var/run/repeater.log"}
command=/usr/local/sbin/repeater
start_precmd="echo Starting ${name}."
start_cmd="daemon ${command} ${repeater_viewer_port} ${repeater_server_port} > ${repeater_log} 2>&1"

run_rc_command "$1"
