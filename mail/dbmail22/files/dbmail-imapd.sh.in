#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: dbmail-imapd
# REQUIRE: DAEMON
# KEYWORD: shutdown

#
# Add the following lines to /etc/rc.conf to enable dbmail-imapd: 
#
#dbmail_imapd_enable="YES"
#
# See dbmail-imapd(8) for flags
#

. %%RC_SUBR%%

name=dbmail_imapd
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/dbmail-imapd
pidfile=/var/run/dbmail-imapd.pid
required_files=%%PREFIX%%/etc/dbmail.conf

# read settings, set default values
load_rc_config "$name"
: ${dbmail_imapd_enable="NO"}
: ${dbmail_imapd_flags=""}

run_rc_command "$1"
