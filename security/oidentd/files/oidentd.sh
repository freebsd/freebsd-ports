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
required_files=%%PREFIX%%/etc/${name}.conf

# set defaults

oidentd_enable=${oidentd_enable:-"NO"}
oidentd_flags=${oidentd_flags:-""}

load_rc_config ${name}
run_rc_command "$1"
