#!/bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/print/clibpdf/files/Attic/esecanna.sh,v 1.1 2000-08-22 14:11:10 knu Exp $

esecannaserver="!!PREFIX!!/sbin/esecannaserver"

case "$1" in
start)
	if [ -f !!PREFIX!!/vje30/.version ] \
	 && grep -qw 'FREE TRIAL VERSION' !!PREFIX!!/vje30/.version; then
	    echo ''
	    echo 'esecanna:'
	    echo '  Using VJE-Delta 3.0 trial, it is unable to connect to vjed on startup.'
	    echo '  Please execute $esecannaserver manually after once you run vje.'
	    exit 1
	fi

	if [ -x $esecannaserver ]; then
	    rm -f /tmp/.iroha_unix/IROHA
	    echo -n ' esecanna: '
	    $esecannaserver
	fi
	;;
stop)
	pidfile="/var/run/esecanna.pid"
	if [ -f $pidfile ]; then
	    kill `cat $pidfile` && echo -n ' esecanna'
	    rm $pidfile
	else
	    echo ' esecanna: not running'
	fi
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
