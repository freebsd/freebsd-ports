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
#freshclam_enable"YES"
#
# See freshclam(1) for flags
#

. %%RC_SUBR%%

name=freshclam
rcvar=`set_rcvar`

command=%%PREFIX%%/bin/freshclam
required_dirs=%%DATADIR%%
required_files=%%PREFIX%%/etc/freshclam.conf


# set defaults

freshclam_enable=${freshclam_enable:-"NO"}
freshclam_flags=${freshclam_flags:-"--daemon"}

load_rc_config $name
run_rc_command "$1"
