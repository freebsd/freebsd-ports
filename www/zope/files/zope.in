#!/bin/sh

# Start or stop zope
# $FreeBSD$

# PROVIDE: zope
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: shutdown

# Define these zope_* variables in one of these files:
#       /etc/rc.conf
#       /etc/rc.conf.local
#       /etc/rc.conf.d/zope
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
zope_enable=${zope_enable:-"NO"}        # Enable zope
zope_instances=${zope_instances:-""}    # List of instancehome dirs

. %%RC_SUBR%%

name="zope"
rcvar=`set_rcvar`
load_rc_config $name
extra_commands="status"

if checkyesno zope_enable; then
    for instance in $zope_instances; do
	required_files="${instance}/etc/${name}.conf ${instance}/bin/zopectl"
	zope_command="${instance}/bin/zopectl"
	start_cmd="${zope_command} start"
	stop_cmd="${zope_command} stop"
	restart_cmd="${zope_command} restart"
	status_cmd="${zope_command} status"
	echo -n "Zope instance ${instance} -> "
	run_rc_command "$1"
    done
fi
