#!/bin/sh
#
# @(#) $FreeBSD$

# PROVIDE: %%PORTNAME%%
# REQUIRE: LOGIN abi
# BEFORE:  securelevel
# KEYWORD: FreeBSD shutdown

# Add the following line to /etc/rc.conf to enable `%%PORTNAME%%':
#
#%%PORTNAME%%_enable="YES"
#
# Other rc.conf variables:
#
#  %%PORTNAME%%_flags    Set to "-v" for verbose mode.
#

. %%RC_SUBR%%

name="%%PORTNAME%%"
rcvar=`set_rcvar`

command="%%PREFIX%%/sbin/%%PORTNAME%%"
command_args="-e"

# %%PORTNAME%% is a command to be run during startup and shutdown, not a
# long running daemon process.  There's no pidfile to check, and it's
# hard to tell if %%PORTNAME%% is enabled or not -- just run '%%PORTNAME%% -e' to
# force enable it, '%%PORTNAME%% -d' to disable.

stop_cmd="stop_cmd"
stop_cmd()
{
    $command -d
}

status_cmd="status_cmd"
status_cmd()
{
    echo "Can't check %%PORTNAME%% status"
}

load_rc_config "$name"
: ${%%PORTNAME%%_enable="NO"}
: ${%%PORTNAME%%_flags=""}

run_rc_command "$1"
