#!/bin/sh
#
#  ekpd

PATH=/usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin
DAEMON=/usr/local/libexec/ekpd
LOCK=/var/ekpd/lpr_lock

NAME=ekpd

[ -f $DAEMON ] || exit 0

OLDMASK=`umask`
umask 000

case "$1" in

    start)
	if [ -x $DAEMON ]; then
	    echo -n "Starting $NAME:"
	    [ ! -d /var/ekpd ] && mkdir -p /var/ekpd && chmod 1777 /var/ekpd
	    [ ! -e /var/ekpd/ekplp0 ] && rm -f /var/ekpd/ekplp0 && \
		mkfifo -m 666 /var/ekpd/ekplp0
	    $DAEMON 2>/dev/null
	    echo
	fi
	;;

    stop)
	echo -n "Stopping ekpd:"
	killall ${NAME} 2>/dev/null
	echo
	;;

    restart)
	$0 stop
	sleep 2
	$0 start
	;;

    *)
	echo "Usage: ekpd { start | stop | restart }" >&2
	exit 1
	;;
esac

umask $OLDMASK
exit 0
