#!/bin/sh
#
# $FreeBSD$

slapd_program=@@PREFIX@@/libexec/slapd

# Uncomment one of the following:
#
# IPv4 Only
#slapd_args='-u ldap -g ldap -h ldap://0.0.0.0'
#
# IPv6 and IPv4
#slapd_ags='-u ldap -g ldap -h "ldap://[::] ldap://0.0.0.0"'
#
# IPv6 Only
#slapd_args='-u ldap -g ldap -h ldap://[::]'
#
#
slapd_args="-u ldap -g ldap"

pidfile=/var/run/ldap/slapd.pid

case "$1" in
start)
    if [ -x $slapd ]; then
	echo -n ' slapd'
	eval ${slapd_program} ${slapd_args}

    fi
    ;;
stop)
    if [ -f $pidfile ]; then
	kill `cat $pidfile`
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
