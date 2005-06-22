#!/bin/sh
# $FreeBSD$

# PROVIDE: zerowait
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: shutdown

# Define these zerowait_enable variables in one of these files:
#       /etc/rc.conf
#       /etc/rc.conf.local
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
. %%RC_SUBR%%

name="zerowait"
rcvar=`set_rcvar`
command="%%PREFIX%%/sbin/0W-httpd"
args="-c %%PREFIX%%/etc/0W-httpd/httpd.conf"
required_files="%%PREFIX%%/etc/0W-httpd/httpd.conf"
pidfile="%%PREFIX%%/0W-httpd/pids/httpd"

load_rc_config $name
: ${zerowait_enable="NO"}

start_cmd="echo \"Starting ${name}.\"; /usr/bin/limits -U www ${command}"

run_rc_command "$1"
