#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: clamav-milter
# REQUIRE: LOGIN
# BEFORE: mail
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable clamav-milter:
#
#clamav_milter_enable="YES"
#
# See clamav-milter(1) for flags
#

. %%RC_SUBR%%

name=clamav_milter
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/clamav-milter
required_dirs=%%DATADIR%%
required_files=%%PREFIX%%/etc/clamav.conf

start_precmd=start_precmd

start_precmd()
{
	if [ -S "$clamav_milter_socket" ]; then
		warn "Stale socket $clamav_milter_socket removed."
		rm "$clamav_milter_socket"
	fi
}

# set defaults

clamav_milter_enable=${clamav_milter_enable:-"NO"}
clamav_milter_socket=${clamav_milter_socket:-"%%CLAMAV_MILTER_SOCKET%%"}
clamav_milter_flags=${clamav_milter_flags:-"--postmaster-only --local --outgoing --max-children=50"}

load_rc_config $name

# add socket to any given argument
clamav_milter_flags="${clamav_milter_flags} ${clamav_milter_socket}"
run_rc_command "$1"
