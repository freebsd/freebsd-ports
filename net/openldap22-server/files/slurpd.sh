#!/bin/sh
#
# $FreeBSD$

slurpd_program=%%PREFIX%%/libexec/slurpd

slurpd_enable="NO"

slurpd_args=

# Add the following line to /etc/rc.conf to enable slurpd:
#
#slurpd_enable="YES"
#
# See slurpd(8) for details
#

# Suck in the configuration variables.
if [ -r /etc/defaults/rc.conf ]; then
    . /etc/defaults/rc.conf
    source_rc_confs
elif [ -r /etc/rc.conf ]; then
    . /etc/rc.conf
fi

case "$slurpd_enable" in
[Yy][Ee][Ss])
    case "$1" in
    start)
        if [ -x ${slurpd_program} ]; then
            echo -n ' slurpd'
            ${slurpd_program} ${slurpd_args} 
        fi
        ;;
    stop)
        if ! killall `basename ${slurpd_program}`; then
            echo ' slurpd: not running'
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
