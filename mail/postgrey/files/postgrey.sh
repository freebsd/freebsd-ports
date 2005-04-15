#!/bin/sh
# $FreeBSD$
#

# PROVIDE: postgrey
# REQUIRE: LOGIN
# BEFORE: mail
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable postgrey:
#
# postgrey_enable="YES"
#
# See perldoc postgrey for flags
#

. %%RC_SUBR%%

name=postgrey
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/postgrey
required_dirs=/var/db/postgrey
extra_commands=reload

stop_postcmd=stop_postcmd

stop_postcmd()
{
  rm -f $pidfile
}

# set defaults

postgrey_enable=${postgrey_enable:-"NO"}
postgrey_pidfile=${postgrey_pidfile:-"/var/run/postgrey.pid"}
postgrey_flags=${postgrey_flags:-"--pidfile=${postgrey_pidfile} \
	--inet=10023 -d --user=postgrey --group=postgrey --dbdir=/var/db/postgrey"}

pidfile="${postgrey_pidfile}"

load_rc_config $name
run_rc_command "$1"
