#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: xfs
# REQUIRE: cleartmp
# BEFORE:  LOGIN
# KEYWORD: FreeBSD

# The following variables are provided to control startup of X font server in
# rc configuration file (eg /etc/rc.conf):
# xfs_enable (bool):	Set to "NO" by default.
#			Set it to "YES" to enable X font server
# xfs_config (str):	Set to "%%PREFIX%%/lib/X11/fs/config" by default.
#			Configuration file for X font server.
#
# Please see xfs(1), rc.conf(5) and rc(8) for further details.

. %%RC_SUBR%%

name="xfs"
rcvar=`set_rcvar`

# Set defaults
[ -z "$xfs_enable" ] && xfs_enable="NO"
[ -z "$xfs_config" ] && xfs_config="%%PREFIX%%/lib/X11/fs/config"

load_rc_config $name

command="%%PREFIX%%/bin/${name}"
command_args="-config ${xfs_config} -daemon"
required_files="$xfs_config"
extra_commands="reload"

run_rc_command "$1"
