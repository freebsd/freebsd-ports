#!/bin/sh

case "$1" in
start)
	[ -x %%PREFIX%%/libexec/popa3d ] && %%PREFIX%%/libexec/popa3d -D && echo -n ' popa3d'
	;;
stop)
	killall popa3d
	;;
*)
	echo "Usage: ${0##*/}: { start | stop }" >&2
	exit 64
	;;
esac

exit 0
