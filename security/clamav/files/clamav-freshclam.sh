#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: freshclam
# REQUIRE: LOGIN
# BEFORE: mail
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable freshclam:
#
#clamav_freshclam_enable="YES"
#
# See freshclam(8) for flags
#

. %%RC_SUBR%%

name=clamav_freshclam
rcvar=`set_rcvar`

command=%%PREFIX%%/bin/freshclam
required_dirs=%%DATADIR%%

# set defaults

clamav_freshclam_enable=${clamav_freshclam_enable:-"NO"}
clamav_freshclam_flags=${clamav_freshclam_flags:-"--checks=1 --datadir=%%DATADIR%% --daemon-notify=%%PREFIX%%/etc/clamav.conf --log=/var/log/clamav/freshclam.log"}

load_rc_config $name

# add --daemon to any given arguments
clamav_freshclam_flags="${clamav_freshclam_flags} --daemon"
run_rc_command "$1"
