#!/bin/sh
#

case "$1" in
start|restart)
    %%PREFIX%%/sbin/env4801 -i
    ;;
stop)
    ;;
esac
