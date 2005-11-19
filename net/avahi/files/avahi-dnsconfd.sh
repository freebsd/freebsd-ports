#!/bin/sh
#
# $FreeBSD$
#
# PROVIDE: avahi_dnsconfd
# REQUIRE: DAEMON dbus
# KEYWORD: FreeBSD
#
# avahi-dnsconfd connects to a running avahi-daemon and runs  the script
# %%PREFIX%%/etc/avahi/dnsconf.action for each unicast DNS server that
# is announced on the local LAN. This is useful for configuring unicast
# DNS servers in a DHCP-like fashion with mDNS.
#

avahi_dnsconfd_enable=${avahi_dnsconfd_enable-"NO"}
avahi_dnsconfd_flags=${avahi_dnsconfd_flags-"-D"}

. %%RC_SUBR%%

name=avahi_dnsconfd
rcvar=`set_rcvar`

start_cmd=avahi_dnsconfd_start
stop_cmd=avahi_dnsconfd_stop

avahi_dnsconfd_bin=%%PREFIX%%/sbin/avahi-daemon

avahi_dnsconfd_start() {
    checkyesno avahi_dnsconfd_enable && echo "Starting avahi-dnsconfd." && \
    	${avahi_dnsconfd_bin} ${avahi_dnsconfd_flags}
}

avahi_dnsconfd_stop() {
    checkyesno avahi_dnsconfd_enable && echo "Stopping avahi-dnsconfd." && \
    	${avahi_dnsconfd_bin} -k
}

load_rc_config ${name}
run_rc_command "$1"
