#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: siproxd
# REQUIRE: DAEMON
# KEYWORD: FreeBSD
#
# NOTE for FreeBSD 5.0+:
# If you want this script to start with the base rc scripts
# move siproxd.sh to /etc/rc.d/siproxd

prefix=%%PREFIX%%

# Define these siproxd_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/siproxd
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
siproxd_enable=${siproxd_enable:-"NO"}	# Enable siproxd
siproxd_flags=${siproxd_flags:-""}	# Flags to siproxd program
#siproxd_program="${prefix}/sbin/siproxd"	# Location of siproxd

. %%RC_SUBR%%

name="siproxd"
rcvar=`set_rcvar`
command="${prefix}/sbin/${name}"

load_rc_config $name

case $1 in
    start)
    run_rc_command "$1" 2> /dev/null
    ;;
    *)
    run_rc_command "$1"
    ;;
esac
