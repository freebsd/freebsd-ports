#!/bin/sh
#
# $FreeBSD: ports/security/clamav-devel/files/freshclam.sh
#

# PROVIDE: freshclam
# REQUIRE: LOGIN clamd
# BEFORE: mail
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable the freshclam daemon:
#
#clamav_freshclam_enable="YES"
#
# See freshclam(1) for flags
#

. %%RC_SUBR%%

name=clamav_freshclam
rcvar=`set_rcvar`

command=%%PREFIX%%/bin/freshclam
pidfile=%%RUNDIR%%/freshclam.pid
command_args="--daemon"
required_dirs=%%DBDIR%%
required_files=%%PREFIX%%/etc/freshclam.conf

# read settings, set default values
load_rc_config "$name"
: ${clamav_freshclam_enable="NO"}
: ${clamav_freshclam_flags=""}

run_rc_command "$1"
