#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: dovecot
# REQUIRE: LOGIN
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable dovecot:
#
#dovecot_enable="YES"
#
dovecot_enable="NO"

. %%RC_SUBR%%

name=dovecot
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/${name}
required_files=%%PREFIX%%/etc/${name}.conf

load_rc_config ${name}
run_rc_command "$1"
