#!/bin/sh

kmoddir=@@PREFIX@@/modules
kmod=est.ko

case "$1" in
start)
	if [ -x $kmoddir/$kmod ]; then
	    echo -n ' est'
	    /sbin/kldload $kmoddir/$kmod
	fi
	;;
stop)
	/sbin/kldunload $kmod && echo -n ' est'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac
