#!/bin/sh
#
# $FreeBSD$

USER=httptunnel

HTS=%%PREFIX%%/bin/hts		# The installed hts program
HTSPORT=			# [host:]port to listen for htc connection
HTSFORWARD=			# Talk to this socket
HTSDEVICE=			# *or* talk to this device

HTC=%%PREFIX%%/bin/htc		# The installed htc program
HTCPORT=			# host:port where hts is running
HTCFORWARD=			# Talk to this socket
HTCDEVICE=			# *or* talk to this device

HTCPROXY=			# host:port of proxy to talk to hts via
HTCPROXYAUTH=			# user:password to pass to proxy
HTCPROXYBUFFER=1K		# Buffer size for buffered proxies
HTCBROWSER='Mozilla/4.7 [en] (X11; I; Linux 2.2.12 i386)'  # Pretend to be this
HTCARGS=-S			# Any other arguments required

case $1 in
start)
	if [ -n "$HTSPORT" -a -x $HTS ]; then
		[ -n "$HTSFORWARD" ] && args="-F $HTSFORWARD"
		[ -n "$HTSDEVICE" ] && args="-d $HTSDEVICE"
		su -m $USER -c "$HTS $args $HTSPORT" && echo -n ' hts'
	fi

	if [ -n "$HTCPORT" -a -x $HTC ]; then
		[ -n "$HTCFORWARD" ] && args="-F $HTCFORWARD"
		[ -n "$HTCDEVICE" ] && args="-d $HTCDEVICE"
		[ -n "$HTCBROWSER" ] && args="-U \"$HTCBROWSER\" $args"
		if [ -n "$HTCPROXY" ]; then
			[ -n "$HTCPROXYBUFFER" ] &&
				args="-B $HTCPROXYBUFFER $args"
			if [ -n "$HTCPROXYAUTH" ]
			then
				if [ -f "$HTCPROXYAUTH" ]
				then
					args="--proxy-authorization-file $HTCPROXYAUTH $args"
				else
					args="-A $HTCPROXYAUTH $args"
				fi
			fi
			args="-P $HTCPROXY $args"
		fi
		su -m $USER -c "$HTC $args $HTCARGS $HTCPORT" && echo -n ' htc'
	fi
	;;
stop)
	killall htc && echo -n ' htc'
	killall hts && echo -n ' hts'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
