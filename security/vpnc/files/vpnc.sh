#! /bin/sh

PREFIX=%%PREFIX%%
PIDFILE=/var/run/vpnc.pid

# change these variables and activate comments
# below to get a full tunnel
VPNGATEWAY=vpn.rwth-aachen.de
ROUTER=192.168.111.2

case "$1" in
start)
	[ -x ${PREFIX}/sbin/vpnc ] && ${PREFIX}/sbin/vpnc --pid-file ${PIDFILE} &&
	# route add -host ${VPNGATEWAY} ${ROUTER}
	# route delete default && 
	# route add default -interface tun0 &&
	echo -n ' vpnc'
	;;
stop)
	kill `cat ${PIDFILE}`
	# route delete default &&
	# route add default ${ROUTER}
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
