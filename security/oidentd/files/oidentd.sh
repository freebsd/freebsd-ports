#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: oidentd
# REQUIRE: DAEMON
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable dovecot:
#
#oidentd_enable="YES"
#
# See oidentd(8) for flags.
#

. %%RC_SUBR%%

name=oidentd
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/${name}

# set defaults

oidentd_enable=${oidentd_enable:-"NO"}
oidentd_conf=${oidentd_conf:-"%%PREFIX%%/etc/${name}.conf"}
oidentd_flags=${oidentd_flags:-""}

oidentd_precmd ()
{
	if [ -n "${oidentd_conf}" ]; then
		rc_flags="${rc_flags} -C ${oidentd_conf}"
	fi
}

load_rc_config ${name}

start_precmd=${name}_precmd
required_files=${oidentd_conf}

run_rc_command "$1"
