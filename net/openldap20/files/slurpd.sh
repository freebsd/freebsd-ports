#!/bin/sh
#
# $FreeBSD$

slurpd_program=@@PREFIX@@/libexec/slurpd

slurpd_args=

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

exit 0
