#!/bin/sh

case "$1" in
	start)
		/sbin/ldconfig -m %%PREFIX%%/lib
		;;
	stop)
		;;
	*)
		echo ""
		echo "Usage: `basename $0` { start | stop }"
		echo ""
		echo 64
		;;
esac
