#!/bin/sh

PREFIX=%%PREFIX%%

case "$1" in

start)
	${PREFIX}/bin/xfstt --sync >/dev/null
	${PREFIX}/bin/xfstt --user nobody --notcp --daemon && echo -n ' xfstt'
	;;
stop)
	/usr/bin/killall xfstt 2>/dev/null && echo -n ' xfstt'
	;;
*)
	echo "$0 start | stop"
	;;

esac
