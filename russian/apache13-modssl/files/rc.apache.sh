#!/bin/sh

case $1 in
start)
	!!PREFIX!!/sbin/apachectl start
	echo -n ' apache'
    ;;

stop)
	!!PREFIX!!/sbin/apachectl stop
    ;;

*)
    echo "usage: `basename $0` {start|stop}" >&2
    exit 64
    ;;
esac
