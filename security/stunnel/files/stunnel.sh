#!/bin/sh
#
# A sample stunnel startup script written by martti.kuparinen@ericsson.com
#
# $FreeBSD$
#

# Where is the program
STUNNEL="!!PREFIX!!/sbin/stunnel"

case "$1" in
    start)
        ${STUNNEL} !!PREFIX!!/etc/stunnel/stunnel.conf
        ;;

    stop)
        killall `basename ${STUNNEL}`
        ;;

    *)
        echo ""
        echo "Usage: `basename $0` { start | stop }"
        echo ""
        ;;
esac
