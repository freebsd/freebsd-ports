#!/bin/sh

case "$1" in
start)
    if [ -x %%PREFIX%%/interchange/bin/interchange ]; then
	su -m $(cat %%PREFIX%%/interchange/_uid) \
		-c '%%PREFIX%%/interchange/bin/interchange >/dev/null' && \
		echo -n ' interchange'
    fi
    ;;
stop)
    if [ -r %%PREFIX%%/interchange/etc/interchange.pid ]; then
	kill $(cat %%PREFIX%%/interchange/etc/interchange.pid) && \
		echo -n ' interchange'
    fi
    ;;
*)
    echo "Usage: `basename $0` {start|stop}" >&2
    ;;
esac

