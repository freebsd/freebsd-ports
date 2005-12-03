#!/bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/www/apache22/files/Attic/apache.sh,v 1.9 2005-12-03 22:02:58 clement Exp $
#

# PROVIDE: apache22
# REQUIRE: NETWORKING SERVERS
# BEFORE: DAEMON
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable apache22:
# apache22_enable (bool):      Set to "NO" by default.
#                             Set it to "YES" to enable apache22
# apache22ssl_enable (bool):   Set to "NO" by default.
#                             Set it to "YES" to start apache with SSL   
#                             (if <IfDefined SSL> exists in httpd.conf)
# apache22limits_enable (bool):Set to "NO" by default.
#                             Set it to yes to run `limits $limits_args`
#                             just before apache starts.
# apache22_flags (str):        Set to "" by default.
#                             Extra flags passed to start command.
# apache22limits_args (str):   Default to "-e -C daemon"
#                             Arguments of pre-start limits run.
#
. %%RC_SUBR%%

name="apache22"
rcvar=`set_rcvar`

start_precmd="apache22_precmd"
restart_precmd="apache22_checkconfig"
reload_precmd="apache22_checkconfig"
command="%%PREFIX%%/sbin/httpd"
pidfile="/var/run/httpd.pid"
required_files=%%PREFIX%%/etc/apache22/httpd.conf

[ -z "$apache22_enable" ]       && apache22_enable="NO"
[ -z "$apache22ssl_enable" ]    && apache22ssl_enable="NO"
[ -z "$apache22_flags" ]        && apache22_flags=""
[ -z "$apache22limits_enable" ] && apache22limits_enable="NO"
[ -z "$apache22limits_args" ]   && apache22limits_args="-e -C daemon"

load_rc_config $name

checkyesno apache22ssl_enable && \
			apache22_flags="-DSSL $apache22_flags"

apache22_checkconfig()
{
	echo "Performing sanity check on apache22 configuration:"
	${command} ${apache22_flags} -t
}

apache22_precmd() 
{
	if test -f %%PREFIX%%/sbin/envvars
	then
		. %%PREFIX%%/sbin/envvars
	fi
	if checkyesno apache22limits_enable
	then
		eval `/usr/bin/limits ${apache22limits_args}` 2>/dev/null
	else
		return 0
        fi

}

sig_reload=SIGUSR1

extra_commands="reload"
run_rc_command "$1"
