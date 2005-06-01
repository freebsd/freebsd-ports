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
# apache2_profiles (string):  Undefined by default. Define here your profiles.
# apache2ssl_enable (bool):   Set to "NO" by default.
#                             Set it to "YES" to start apache with SSL   
#                             (if <IfDefined SSL> exists in httpd.conf)
# apache2limits_enable (bool):Set to "NO" by default.
#                             Set it to yes to run `limits $limits_args`
#                             just before apache starts.
# apache2_flags (str):        Set to "" by default.
#                             Extra flags passed to start command.
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
_pidprefix="/var/run/httpd"
pidfile="${_pidprefix}.pid"
required_files=%%PREFIX%%/etc/apache2/httpd.conf

[ -z "${apache2_enable}" ]       && apache2_enable="NO"
[ -z "${apache2ssl_enable}" ]    && apache2ssl_enable="NO"
[ -z "${apache2_flags}" ]        && apache2_flags=""
[ -z "${apache2limits_enable}" ] && apache2limits_enable="NO"
[ -z "${apache2limits_args}" ]   && apache2limits_args="-e -C daemon"
[ -z "${apache2_configfile}" ]   && apache2_configfile=""

load_rc_config $name

if [ -n "${2}" ]; then
	profile=${2}
	if [ "x${apache2_profiles}" != "x" ]; then
		pidfile="${_pidprefix}.${profile}.pid"
		eval apache2_configfile=\${apache2_${profile}_configfile}
		[ "x${apache2_configfile}" = "x" ] && {
			echo "You must define a configuration file (apache2_${profile}_configfile)"
			exit 1
		}
		eval apache2_enable=\${apache2_${profile}_enable:-YES}
		eval apache2ssl_enable=\${apache2ssl_${profile}_enable:-NO}
		eval apache2_flags=\${apache2_${profile}_flags:-${apache2_flags}}
		eval apache2limits_enable=\${apache2limits_${profile}_enable:-${apache2limits_enable}}
		eval apache2limits_args=\${apache2limits_${profile}_args:-${apache2limits_args}}
		pidfile="${_pidprefix}.${profile}.pid"
		apache2_flags="-c \"PidFile ${pidfile}\" ${apache2_flags}"
	else
		echo "$0: extra argument ignored"
	fi
else
	if [ "x${apache2_profiles}" != "x" ]; then
	for profile in ${apache2_profiles}; do
		echo "===> apache2 profile: ${profile}"
		$0 $1 $profile
		retcode=$?
		if [ "$?" -ne 0 ]; then
			failed="${profile} ({$retcode}) ${failed}"
		else
			success="${profile} ${success}"
		fi
	done
	exit 0
	fi
fi

checkyesno apache2ssl_enable && \
			apache2_flags="-DSSL $apache2_flags"

[ "x${apache2_configfile}" != "x" ] && {
			apache2_flags="-f ${apache2_configfile} ${apache2_flags}"
			required_files=${apache2_configfile}
}

apache2_checkconfig()
{
	echo "Performing sanity check on apache2 configuration:"
	${command} ${apache2_flags} -t
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
	echo DEBUG ${apache2_flags}
}

sig_reload=SIGUSR1

extra_commands="reload"
run_rc_command "$1"
