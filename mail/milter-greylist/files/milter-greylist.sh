#!/bin/sh
# $FreeBSD$

# PROVIDE: miltergreylist
# REQUIRE: LOGIN
# BEFORE: sendmail
# KEYWORD: milter-greylist

# Define these miltergreylist_* variables in one of these files:
#       /etc/rc.conf
#       /etc/rc.conf.miltergreylist
#       /etc/rc.conf.d/miltergreylist
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
miltergreylist_enable="NO"
miltergreylist_runas="smmsp"
miltergreylist_pidfile="/var/run/milter-greylist.pid"
miltergreylist_sockfile="/var/milter-greylist/milter-greylist.sock"
miltergreylist_cfgfile="%%PREFIX%%/etc/mail/greylist.conf"
miltergreylist_flags="-P $miltergreylist_pidfile -f $miltergreylist_cfgfile
 -p $miltergreylist_sockfile -u $miltergreylist_runas"

. %%RC_SUBR%%

name="miltergreylist"
rcvar=`set_rcvar`
command="%%PREFIX%%/bin/milter-greylist"

load_rc_config $name

run_rc_command "$1"
