#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
	echo "$0: Cannot determine the PREFIX" >&2
	exit 1
fi

case "$1" in
start)
	if [ -x ${PREFIX}/modules/matrix_saver.ko ]; then
		echo -n ' matrix_saver'
		kldload ${PREFIX}/modules/matrix_saver.ko
	fi
	;;
stop)
	kldunload -v -n matrix_saver && echo -n ' matrix_saver'
	;;
*)
	echo "Usage: $0 {start|stop}" >&2
	exit 1
	;;
esac
