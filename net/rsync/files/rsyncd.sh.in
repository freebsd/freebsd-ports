#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: %%NAME%%
# REQUIRE: LOGIN
# BEFORE:  securelevel
# KEYWORD: FreeBSD shutdown

# Add the following line to /etc/rc.conf to enable `%%NAME%%':
#
#%%NAME%%_enable="YES"
#
# See rsync(1) for %%NAME%%_flags
#

. "%%RC_SUBR%%"

name="%%NAME%%"
rcvar=`set_rcvar`

command="%%PREFIX%%/bin/rsync"
command_args="--daemon"
pidfile="/var/run/$name.pid"
required_files="%%PREFIX%%/etc/$name.conf"

# read configuration and set defaults
load_rc_config "$name"
: ${%%NAME%%_enable="NO"}
: ${%%NAME%%_flags=""}

run_rc_command "$1"
