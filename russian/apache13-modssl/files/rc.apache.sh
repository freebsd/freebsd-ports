#!/bin/sh

case $1 in
start)
	!!PREFIX!!/sbin/apachectl startssl > /dev/null && echo -n ' apache'
    ;;

stop)
	!!PREFIX!!/sbin/apachectl stop > /dev/null
    ;;

*)
    echo "usage: `basename $0` {start|stop}" >&2
    exit 64
    ;;
esac
