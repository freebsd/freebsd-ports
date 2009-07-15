#!/bin/sh

# Start or stop zope
# $FreeBSD$

# PROVIDE: zeo
# REQUIRE: DAEMON
# BEFORE: zope
# KEYWORD: shutdown

# Define these zope_* variables in one of these files:
#       /etc/rc.conf
#       /etc/rc.conf.local
#       /etc/rc.conf.d/zeo
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
zeo_enable=${zeo_enable:-"NO"}        # Enable zeo server
zeo_instances=${zeo_instances:-""}    # List of instancehome dirs

. %%RC_SUBR%%

name="zeo"
rcvar=`set_rcvar`
load_rc_config $name
extra_commands="status"

if checkyesno zeo_enable; then
    for instance in $zeo_instances; do
	required_files="${instance}/etc/${name}.conf ${instance}/bin/zeoctl"
	zeo_command="${instance}/bin/zeoctl"
	start_cmd="${zeo_command} start"
	stop_cmd="${zeo_command} stop"
	restart_cmd="${zeo_command} restart"
	status_cmd="${zeo_command} status"
	echo -n "Zeo instance ${instance} -> "
	run_rc_command "$1"
    done
fi
