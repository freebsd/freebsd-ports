#! /bin/sh
#
# $FreeBSD$
#

umask 022
arg=${1:-start}

nessusd_bin=%%PREFIX%%/sbin/nessusd
nessus_arg="-D"
kill_arg=nessusd

echo -n " nessusd"

case $arg in
start)
	test -x $nessusd_bin || exit 1
	$nessusd_bin $nessus_arg
	;;
stop)
	killall $kill_arg > /dev/null 2>&1
	;;
restart)
	killall $kill_arg > /dev/null 2>&1
	test -x $nessusd_bin || exit 1
	$nessusd_bin $nessus_arg
	;;
esac
