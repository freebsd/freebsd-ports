#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: tenshi
# REQUIRE: LOGIN
# KEYWORD: FreeBSD shutdown

# Add the following lines to /etc/rc.conf to enable `tenshi':
#
#tenshi_enable="YES"
#

. '%%RC_SUBR%%'

name='tenshi'
rcvar=`set_rcvar`

extra_commands='reload'

command='%%PREFIX%%/bin/tenshi'
command_interpreter='%%PERL%%'

pidfile='/var/run/tenshi.pid'

required_files='%%PREFIX%%/etc/tenshi.conf'

# set defaults

tenshi_enable="${tenshi_enable:-NO}"

load_rc_config "$name"
run_rc_command "$1"
