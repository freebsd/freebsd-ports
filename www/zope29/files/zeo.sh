#!/bin/sh

# Start or stop zope
# $FreeBSD$

# PROVIDE: zeo
# REQUIRE: DAEMON
# BEFORE: zope
# KEYWORD: FreeBSD shutdown
#
prefix=%%PREFIX%%

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

if checkyesno zeo_enable; then

	case "$1" in
		start)
			echo "Starting Zeo"
		;;
		stop)
			echo "Stopping Zeo"
		;;
		restart)
			echo "Restarting Zeo"
		;;
		*)
			echo "Unknown action \"$1\""
		;;
	esac

	for instance in $zeo_instances
	do
		if [ -r ${instance}/etc/${name}.conf -a -x ${instance}/bin/zeoctl ]; then
			echo -n "       Instance ${instance} -> "
			${instance}/bin/zeoctl $1
		fi
	done
fi
