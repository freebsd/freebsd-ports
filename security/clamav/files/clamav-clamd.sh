#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: clamd
# REQUIRE: LOGIN
# BEFORE: mail
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable clamd:
#
#clamav_clamd_enable="YES"
#
# See clamd(8) for flags
#

. %%RC_SUBR%%

name=clamav_clamd
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/clamd
pidfile=/var/run/clamav/clamd.pid
required_dirs=%%DATADIR%%
required_files=%%PREFIX%%/etc/clamav.conf

start_precmd=start_precmd

start_precmd()
{
	if [ -S "$clamav_clamd_socket" ]; then
		warn "Stale socket $clamav_clamd_socket removed."
		rm "$clamav_clamd_socket"
	fi
}

stop_postcmd=stop_postcmd

stop_postcmd()
{
  rm -f $pidfile
}

# set defaults

clamav_clamd_enable=${clamav_clamd_enable:-"NO"}
clamav_clamd_flags=${clamav_clamd_flags:-""}
clamav_clamd_socket=${clamav_clamd_socket:-"%%CLAMAV_CLAMD_SOCKET%%"}

load_rc_config $name
run_rc_command "$1"
