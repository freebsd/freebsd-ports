#!/bin/sh
#
# radiusd	Start the radius daemon.

NAME1=radiusd
NAME2=radwatch

ARGS="-y -p 1645"

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

RADIUSD=${PREFIX}/sbin/${NAME1}
WATCHER=${PREFIX}/sbin/${NAME2}

test -f $RADIUSD || exit 0

case "$1" in
  start)
	if [ ! -f /var/log/radutmp ]
	then
		:>/var/log/radutmp
	fi
	if [ -x $WATCHER ]
	then
		echo -n ' radwatch'
		$WATCHER $RADIUSD $ARGS
	else
		echo -n ' radiusd'
		$RADIUSD $ARGS
	fi
	;;
  stop)
	if [ -x $WATCHER ]
	then
		echo -n ' radwatch'
		kill -TERM `cat /var/run/$NAME2.pid`
	else
		kill -TERM `cat /var/run/$NAME1.pid`
		echo -n ' radiusd'
	fi
	;;
  reload|force-reload)
	echo "Reloading radiusd configuration files."
	kill -HUP `cat /var/run/$NAME1.pid`
	;;
  restart)
	$0 stop
	sleep 3
	$0 start
	;;
  *)
        echo "Usage: `basename $0` {start|stop|reload|restart}"
        exit 1
esac

exit 0
