#!/bin/sh

PREFIX=%%PREFIX%%/aolserver
CONFIG=${PREFIX}/nsd.tcl

case "$1" in

start)
        ${PREFIX}/bin/nsd8x -t ${CONFIG} -u nobody -g nobody
        ;;

stop)
        ${PREFIX}/bin/nsd8x -t ${CONFIG} -u nobody -g nobody -K
        ;;

*)
        echo "usage: $0 {start|stop}" 1>&2
        exit 64
        ;;

esac
