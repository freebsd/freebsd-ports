#!/bin/sh
#
# $FreeBSD$
#
# PROVIDE: mdnsresponder
# REQUIRE: DAEMON
#
# Howl's mDNSResponder, a Zeroconf (Bonjour) service advertisement daemon.
#

mdnsresponder_enable=${mdnsresponder_enable-"NO"}
mdnsresponder_flags=${mdnsresponder_flags-""}

. %%RC_SUBR%%

name=mdnsresponder
rcvar=`set_rcvar`

start_cmd=mdnsresponder_start
stop_cmd=mdnsresponder_stop

mdnsresponder_start() {
    checkyesno mdnsresponder_enable && echo "Starting mDNSResponder." && \
    	%%PREFIX%%/bin/mDNSResponder ${mdnsresponder_flags}
}

mdnsresponder_stop() {
    checkyesno mdnsresponder_enable && echo "Stopping mDNSResponder." && \
    	killall mDNSResponder
}

load_rc_config ${name}
run_rc_command "$1"
