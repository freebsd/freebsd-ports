#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: apache2
# REQUIRE: NETWORKING SERVERS
# BEFORE: DAEMON
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable apache2:
# apache2_enable (bool):      Set to "NO" by default.
#                             Set it to "YES" to enable apache2
# apache2ssl_enable (bool):   Set to "NO" by default.
#                             Set it to "YES" to start apache with SSL   
#                             (if <IfDefined SSL> exists in httpd.conf)
# apache2limits_enable (bool):Set to "NO" by default.
#                             Set it to yes to run `limits $limits_args`
#                             just before apache starts.
# apache2_flags (str):        Set to "" by default.
#                             Extra flags passed to start command
# apache2limits_args (str):   Default to "-e -C daemon"
#                             Arguments of pre-start limits run.
#
. %%RC_SUBR%%

name="apache2"
rcvar=`set_rcvar`

start_precmd="apache2_precmd"
restart_precmd="apache2_checkconfig"
reload_precmd="apache2_checkconfig"
command="%%PREFIX%%/sbin/httpd"
pidfile="/var/run/httpd.pid"
required_files=%%PREFIX%%/etc/apache2/httpd.conf

[ -z "$apache2_enable" ]       && apache2_enable="NO"
[ -z "$apache2ssl_enable" ]    && apache2ssl_enable="NO"
[ -z "$apache2_flags" ]        && apache2_flags=""
[ -z "$apache2limits_enable" ] && apache2limits_enable="NO"
[ -z "$apache2limits_args" ]   && apache2limits_args="-e -C daemon"

load_rc_config $name

checkyesno apache2ssl_enable && \
			apache2_flags="-DSSL $apache2_flags"

apache2_checkconfig()
{
	echo "Performing sanity check on apache2 configuration:"
	${command} -t
}

apache2_precmd() 
{
	if test -f %%PREFIX%%/sbin/envvars
	then
		. %%PREFIX%%/sbin/envvars
	fi
	if checkyesno apache2limits_enable
	then
		eval `/usr/bin/limits ${apache2limits_args}` 2>/dev/null
	else
		return 0
        fi

}

sig_reload=SIGUSR1

extra_commands="reload"
run_rc_command "$1"
