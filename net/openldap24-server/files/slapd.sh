#!/bin/sh
#
# $FreeBSD$

slapd_program=%%PREFIX%%/libexec/slapd

slapd_pidfile=%%LDAP_RUN_DIR%%/slapd.pid

slapd_enable="NO"

slapd_args=

# Add the following lines to /etc/rc.conf to enable slapd:
#
#slapd_enable="YES"
#slapd_args='-h "ldapi://%2fvar%2frun%2fopenldap%2fldapi/????x-mod=0777 ldap://0.0.0.0/"'
#
# See sldap(8) for details
#
# Create a user 'ldap' and add '-u ldap -g ldap' to slapd_args
# if you want to run slapd as a non-privileged user (recommended)
#

# Suck in the configuration variables.
if [ -r /etc/defaults/rc.conf ]; then
    . /etc/defaults/rc.conf
    source_rc_confs
elif [ -r /etc/rc.conf ]; then
    . /etc/rc.conf
fi

case "$slapd_enable" in
[Yy][Ee][Ss])
    case "$1" in
    start)
        if [ -x ${slapd_program} ]; then
            echo -n ' slapd'
            eval ${slapd_program} ${slapd_args}
        fi
        ;;
    stop)
        if [ -f $slapd_pidfile ]; then
            kill `cat $slapd_pidfile`
            echo -n ' slapd'
        else
            echo ' slapd: not running'
        fi
        ;;
    *)
        echo "Usage: `basename $0` {start|stop}" >&2
        exit 64
        ;;
    esac
    ;;
*)
    ;;
esac

exit 0
