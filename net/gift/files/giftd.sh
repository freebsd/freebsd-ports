#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: giftd
# REQUIRE: DAEMON
# KEYWORD: FreeBSD shutdown

# Define these giftd_* variables in one of these files:
#       /etc/rc.conf
#       /etc/rc.conf.local
#       /etc/rc.conf.d/giftd
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE

giftd_enable="NO"
giftd_flags="-d -q"
giftd_user=""
giftd_local_dir=""

. "%%RC_SUBR%%"

name="giftd"
rcvar=`set_rcvar`
command="%%PREFIX%%/bin/giftd"

required_dirs=${giftd_local_dir}
start_precmd="giftd_check_vars"

giftd_check_vars() 
{
	if [ -z ${giftd_user} ]; then
		giftd_user=$(whoami)
	fi

	if [ $giftd_user = 'root' ]; then
		warn "You should set giftd_user to a non-root user for security reasons"
	fi

	if [ -z ${giftd_local_dir} ]; then
		giftd_local_dir="$(pw usershow $giftd_user | awk -F : '{ print $9 }')/.giFT"
	fi

	rc_flags="${giftd_flags} --local-dir=${giftd_local_dir}"
}

load_rc_config $name
run_rc_command "$1"
