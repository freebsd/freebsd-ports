#!/bin/sh
PID_FILE=/var/run/tclhttpd.pid
case $1 in
	stop)
		if [ -e $PID_FILE ] ; then
			PID=`cat $PID_FILE`
			if kill $PID ; then
				exec rm -f $PID_FILE
			fi
		else
			echo "No $PID_FILE presenet, tclhttpd is, probably, not running"  > /dev/stderr
		fi
		;;
	''|start)
		env LANG=C COMMAND_LINE &
		sleep 2
		if kill -0 $! ; then
			echo -n ' tclhttpd'
			echo $! > $PID_FILE
		else
			exec logger -s "tclhttpd failed to start"
		fi
		;;
esac
