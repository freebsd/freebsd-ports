#!/bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/www/apache21/files/Attic/apache.sh,v 1.8 2005-01-11 13:45:05 clement Exp $
#

# PROVIDE: apache21
# REQUIRE: NETWORKING SERVERS
# BEFORE: DAEMON
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable apache21:
# apache21_enable (bool):      Set to "NO" by default.
#                             Set it to "YES" to enable apache21
# apache21ssl_enable (bool):   Set to "NO" by default.
#                             Set it to "YES" to start apache with SSL   
#                             (if <IfDefined SSL> exists in httpd.conf)
# apache21limits_enable (bool):Set to "NO" by default.
#                             Set it to yes to run `limits $limits_args`
#                             just before apache starts.
# apache21_flags (str):        Set to "" by default.
#                             Extra flags passed to start command.
# apache21limits_args (str):   Default to "-e -C daemon"
#                             Arguments of pre-start limits run.
#
. %%RC_SUBR%%

name="apache21"
rcvar=`set_rcvar`

start_precmd="apache21_precmd"
restart_precmd="apache21_checkconfig"
reload_precmd="apache21_checkconfig"
command="%%PREFIX%%/sbin/httpd"
pidfile="/var/run/httpd.pid"
required_files=%%PREFIX%%/etc/apache21/httpd.conf

[ -z "$apache21_enable" ]       && apache21_enable="NO"
[ -z "$apache21ssl_enable" ]    && apache21ssl_enable="NO"
[ -z "$apache21_flags" ]        && apache21_flags=""
[ -z "$apache21limits_enable" ] && apache21limits_enable="NO"
[ -z "$apache21limits_args" ]   && apache21limits_args="-e -C daemon"

load_rc_config $name

checkyesno apache21ssl_enable && \
			apache21_flags="-DSSL $apache21_flags"

apache21_checkconfig()
{
	echo "Performing sanity check on apache21 configuration:"
	${command} ${apache21_flags} -t
}

apache21_precmd() 
{
	if test -f %%PREFIX%%/sbin/envvars
	then
		. %%PREFIX%%/sbin/envvars
	fi
	if checkyesno apache21limits_enable
	then
		eval `/usr/bin/limits ${apache21limits_args}` 2>/dev/null
	else
		return 0
        fi

}

sig_reload=SIGUSR1

extra_commands="reload"
run_rc_command "$1"
