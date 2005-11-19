#!/bin/sh
#
# $FreeBSD$
#
# PROVIDE: avahi_daemon
# REQUIRE: DAEMON dbus
# KEYWORD: FreeBSD
#
# Avahi's mDNSResponder, a Zeroconf (Bonjour) service advertisement daemon.
#

avahi_daemon_enable=${avahi_daemon_enable-"NO"}
avahi_daemon_flags=${avahi_daemon_flags-"-D"}

. %%RC_SUBR%%

name=avahi_daemon
rcvar=`set_rcvar`

start_cmd=avahi_daemon_start
stop_cmd=avahi_daemon_stop

avahi_daemon_bin=%%PREFIX%%/sbin/avahi-daemon

avahi_daemon_start() {
    checkyesno avahi_daemon_enable && echo "Starting avahi-daemon." && \
    	${avahi_daemon_bin} ${avahi_daemon_flags}
}

avahi_daemon_stop() {
    checkyesno avahi_daemon_enable && echo "Stopping avahi-daemon." && \
    	${avahi_daemon_bin} -k
}

load_rc_config ${name}
run_rc_command "$1"
