#!/bin/sh
# $FreeBSD: /tmp/pcvs/ports/www/apache13-modperl/files/Attic/apache.sh,v 1.3 2006-02-20 20:47:46 dougb Exp $

# PROVIDE: apache
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: shutdown

# Define these apache_* variables in one of these files:
#       /etc/rc.conf
#       /etc/rc.conf.local
#       /etc/rc.conf.d/apache
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
apache_enable="${apache_enable-NO}"
apache_flags=""
apache_pidfile="/var/run/httpd.pid"

. %%RC_SUBR%%

name="apache"
rcvar=`set_rcvar`
command="%%PREFIX%%/sbin/httpd"

load_rc_config $name

pidfile="${apache_pidfile}"

start_precmd="`/usr/bin/limits -e -U www`"

run_rc_command "$1"
