#!/bin/sh

msbindir=/usr/local/libexec/MailScanner
process=MailScanner
config=/usr/local/etc/MailScanner/MailScanner.conf
PIDFILE=/var/run/MailScanner.pid

start_ms()
{
    pid=`ps -axww |
         grep '[ ]'$msbindir/$process |
         awk '{print $1}'`

    if [ "x$pid" = "x" ]; then
	# Quietly try to raise the open_files limit
	ulimit -n 2000 >/dev/null 2>&1
	# Restart it
	PATH=${msbindir}:$PATH
	echo Starting MailScanner...
	cd $msbindir
	$process $config
    else
	echo MailScanner running with pid $pid  
    fi
}

stop_ms()
{
    echo Stopping MailScanner...
    kill -TERM -- -`cat $PIDFILE` 2>/dev/null
    sleep 5
}

_action=${1:-start}

case ${_action} in
start)
	start_ms
	;;

stop)
	stop_ms
	;;

restart)
	stop_ms
	start_ms
	;;

*)
	echo "Usage: `basename $0` {start|stop|restart}" >&2
	exit 64
	;;
esac
exit 0
