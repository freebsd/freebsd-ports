#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: apache
# REQUIRE: NETWORKING SERVERS
# BEFORE: DAEMON
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable apache:
# apache_enable (bool):      Set to "NO" by default.
#                             Set it to "YES" to enable apache
# apachelimits_enable (bool):Set to "NO" by default.
#                             Set it to yes to run `limits $limits_args`
#                             just before apache starts.
# apache_flags (str):        Set to "" by default.
#                             Extra flags passed to start command.
# apachelimits_args (str):   Default to "-e -C daemon"
#                             Arguments of pre-start limits run.
#
. %%RC_SUBR%%

name="apache"
rcvar=`set_rcvar`

start_precmd="apache_precmd"
restart_precmd="apache_checkconfig"
reload_precmd="apache_checkconfig"
command="%%PREFIX%%/sbin/httpsd"
pidfile="/var/run/httpsd.pid"
required_files=%%PREFIX%%/etc/apache/httpsd.conf

[ -z "$apache_enable" ]       && apache_enable="NO"
[ -z "$apache_flags" ]        && apache_flags=""
[ -z "$apachelimits_enable" ] && apachelimits_enable="NO"
[ -z "$apachelimits_args" ]   && apachelimits_args="-e -C daemon"

load_rc_config $name

apache_checkconfig()
{
	echo "Performing sanity check on apache configuration:"
	${command} -t
}

apache_precmd() 
{
	if checkyesno apachelimits_enable
	then
		eval `/usr/bin/limits ${apachelimits_args}` 2>/dev/null
	else
		return 0
        fi

}

sig_reload=SIGUSR1

extra_commands="reload"
run_rc_command "$1"
