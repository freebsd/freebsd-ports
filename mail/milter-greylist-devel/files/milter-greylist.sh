#!/bin/sh
# $FreeBSD: /tmp/pcvs/ports/mail/milter-greylist-devel/files/Attic/milter-greylist.sh,v 1.1 2005-02-03 18:42:24 ume Exp $

# PROVIDE: miltergreylist
# REQUIRE: LOGIN
# BEFORE: sendmail
# KEYWORD: milter-greylist

# Define these miltergreylist_* variables in one of these files:
#       /etc/rc.conf
#       /etc/rc.conf.local
#       /etc/rc.conf.d/miltergreylist
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
miltergreylist_enable=${miltergreylist_enable-"NO"}
miltergreylist_runas=${miltergreylist_runas-"smmsp"}
miltergreylist_pidfile=${miltergreylist_pidfile-"/var/run/milter-greylist.pid"}
miltergreylist_sockfile=${miltergreylist_sockfile-"/var/milter-greylist/milter-greylist.sock"}
miltergreylist_cfgfile=${miltergreylist_cfgfile-"%%PREFIX%%/etc/mail/greylist.conf"}
miltergreylist_flags=${miltergreylist_flags-"-P $miltergreylist_pidfile \
-f $miltergreylist_cfgfile -p $miltergreylist_sockfile -u $miltergreylist_runas"}

. %%RC_SUBR%%

name="miltergreylist"
rcvar=`set_rcvar`
command="%%PREFIX%%/bin/milter-greylist"

load_rc_config $name

run_rc_command "$1"
