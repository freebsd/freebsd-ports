#!/bin/sh

# Start or stop zope
# $FreeBSD: /tmp/pcvs/ports/www/zope/files/Attic/zope.sh,v 1.5 2005-02-18 16:52:17 pav Exp $

# PROVIDE: zope
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown
#
prefix=%%PREFIX%%

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

if checkyesno zope_enable; then

	case "$1" in
		start)
			echo "Starting Zope"
		;;
		stop)
			echo "Stopping Zope"
		;;
		restart)
			echo "Restarting Zope"
		;;
		*)
			echo "Unknown action \"$1\""
		;;
	esac

	for instance in $zope_instances
	do
		if [ -r ${instance}/etc/${name}.conf -a -x ${instance}/bin/zopectl ]; then
			echo -n "       Instance ${instance} -> "
			${instance}/bin/zopectl $1
		fi
	done
fi
