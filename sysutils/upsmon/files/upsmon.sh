#!/bin/sh

case $1 in
start)
	# see !!PREFIX!!/share/doc/upsmon/INSTALL for command line option details

	if [ -x !!PREFIX!!/sbin/upsmond ]; then
		!!PREFIX!!/sbin/upsmond -p /dev/cuaa0 2>&1 > /dev/null && echo -n ' upsmond'
	fi
	;;
stop)
	killall upsmond && echo -n ' upsmond'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
