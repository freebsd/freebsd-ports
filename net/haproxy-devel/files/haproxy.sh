#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: haproxy
# REQUIRE: NETWORKING SERVERS
# BEFORE: DAEMON
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable haproxy:
# haproxy_enable (bool):      Set to "NO" by default.
#                             Set it to "YES" to enable haproxy
# haproxylimits_enable (bool):Set to "NO" by default.
#                             Set it to yes to run `limits $limits_args`
#                             just before haproxy starts.
# haproxy_flags (str):        Set to "" by default.
#                             Extra flags passed to start command
# haproxylimits_args (str):   Default to "-e -C daemon"
#                             Arguments of pre-start limits run.
#
. %%RC_SUBR%%

name="haproxy"
rcvar=`set_rcvar`

command="%%PREFIX%%/sbin/haproxy"
pidfile="/var/run/haproxy.pid"
required_files=%%PREFIX%%/etc/haproxy.conf

[ -z "$haproxy_enable" ]       && haproxy_enable="NO"
[ -z "$haproxy_flags" ]        && haproxy_flags="-p ${pidfile}"
[ -z "$haproxylimits_enable" ] && haproxylimits_enable="NO"
[ -z "$haproxylimits_args" ]   && haproxylimits_args="-e -C daemon"

load_rc_config $name

checkyesno haproxylimits_enable && \
			start_precmd="eval `/usr/bin/limits ${haproxylimits_args}` 2>/dev/null"

sig_gracefulstop=SIGUSR1

haproxy_gracefulstop() {
	echo "Gracefully shutdown haproxy ($rc_pid)"
	kill -${sig_gracefulstop} ${rc_pid}
	}

extra_commands="gracefulstop"
run_rc_command "$1"
