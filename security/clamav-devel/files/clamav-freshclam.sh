#!/bin/sh
#
# $FreeBSD: ports/security/clamav-devel/files/freshclam.sh
#

# PROVIDE: freshclam
# REQUIRE: LOGIN
# BEFORE: mail
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable freshclam daemon:
#
#clamav_freshclam_enable="YES"
#
# See freshclam(1) for flags
#

. %%RC_SUBR%%

name=clamav_freshclam
rcvar=`set_rcvar`

command=%%PREFIX%%/bin/freshclam
required_dirs=%%DATADIR%%
required_files=%%PREFIX%%/etc/freshclam.conf

# set defaults

clamav_freshclam_enable=${clamav_freshclam_enable:-"NO"}
clamav_freshclam_flags=${clamav_freshclam_flags:-"--pid=/var/run/clamav/freshclam.pid --daemon-notify=%%PREFIX%%/etc/clamav.conf"}

load_rc_config $name

# add --daemon to any given arguments
clamav_freshclam_flags="${clamav_freshclam_flags} --daemon"
run_rc_command "$1"
