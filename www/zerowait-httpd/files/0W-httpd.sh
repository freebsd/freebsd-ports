#!/bin/sh
# $FreeBSD$

# PROVIDE: 0W-httpd
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: shutdown

# Define these 0Whttpd_* variables in one of these files:
#       /etc/rc.conf
#       /etc/rc.conf.local
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
0Whttpd_enable=${0Whttpd_enable-"NO"}

. %%RC_SUBR%%

name="0Whttpd"
rcvar=`set_rcvar`
command="%%PREFIX%%/sbin/0W-httpd"
args="-c %%PREFIX%%/etc/0W-httpd/httpd.conf"

load_rc_config $name

start_cmd="echo \"Starting ${name}.\"; /usr/bin/limits -U www ${command}"

run_rc_command "$1"
