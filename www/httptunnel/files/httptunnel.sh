#!/bin/sh
#
# $FreeBSD$

HTSPORT=			# [host:]port to listen for htc connection
HTSFORWARD=			# Talk to this socket
HTSDEVICE=			# *or* talk to this device

HTCPORT=			# host:port where hts is running
HTCFORWARD=			# Talk to this socket
HTCDEVICE=			# *or* talk to this device

HTCPROXY=			# host:port of proxy to talk to hts via
HTCPROXYAUTH=			# user:password to pass to proxy
HTCPROXYBUFFER=1K		# Buffer size for buffered proxies
HTCBROWSER='Mozilla/4.7 [en] (X11; I; Linux 2.2.12 i386)'  # Pretend to be this
HTCARGS=-S			# Any other arguments required

if [ -n "$HTSPORT" -a -x /usr/local/bin/hts ]; then
	[ -n "$HTSFORWARD" ] && args="-F $HTSFORWARD"
	[ -n "$HTSDEVICE" ] && args="-d $HTSDEVICE"
	/usr/local/bin/hts $args $HTSPORT && echo -n ' hts'
fi

if [ -n "$HTCPORT" -a -x /usr/local/bin/htc ]; then
	set --
	[ -n "$HTCFORWARD" ] && set -- -F $HTCFORWARD
	[ -n "$HTCDEVICE" ] && set -- -d $HTCDEVICE
	[ -n "$HTCBROWSER" ] && set -- -U "$HTCBROWSER" "$@"
	if [ -n "$HTCPROXY" ]; then
		[ -n "$HTCPROXYBUFFER" ] && set -- -B $HTCPROXYBUFFER "$@"
		[ -n "$HTCPROXYAUTH" ] && set -- -A $HTCPROXYAUTH "$@"
        	set -- -P $HTCPROXY "$@"
	fi
	/usr/local/bin/htc "$@" $HTCARGS $HTCPORT && echo -n ' htc'
fi
