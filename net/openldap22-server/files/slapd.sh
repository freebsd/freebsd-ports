#!/bin/sh
#
# $FreeBSD$

slapd=@@PREFIX@@/libexec/slapd
pidfile=/var/run/slapd.pid

case "$1" in
start)
    if [ -x $slapd ]; then
	echo -n ' slapd'
	$slapd
    fi
    ;;
stop)
    if [ -f $pidfile ]; then
	kill `cat $pidfile`
	telnet localhost ldap </dev/null >/dev/null 2>&1
	echo -n ' slapd'
	rm $pidfile
    else
	echo ' slapd: not running'
    fi
    ;;
*)
    echo "Usage: `basename $0` {start|stop}" >&2
    exit 64
    ;;
esac

exit 0
