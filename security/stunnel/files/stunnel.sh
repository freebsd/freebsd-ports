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
        ${STUNNEL} -d 993 -r localhost:imap -p !!PREFIX!!/etc/stunnel.pem
        ${STUNNEL} -d 995 -r localhost:pop3 -p !!PREFIX!!/etc/stunnel.pem
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
