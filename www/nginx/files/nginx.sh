#!/bin/sh
# $FreeBSD$

# PROVIDE: nginx
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown

# Define these apache_* variables in one of these files:
#       /etc/rc.conf
#       /etc/rc.conf.local
#       /etc/rc.conf.d/apache
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
nginx_enable=${nginx_enable-"NO"}
nginx_flags=${nginx_flags-""}
nginx_pidfile=${nginx_pidfile-"/var/run/nginx.pid"}

. %%RC_SUBR%%

name="nginx"
rcvar=`set_rcvar`
command="%%PREFIX%%/sbin/nginx"

load_rc_config $name

pidfile="${nginx_pidfile}"

start_cmd="echo \"Starting ${name}.\"; /usr/bin/limits -U www ${command} ${nginx_flags}"

run_rc_command "$1"
