#! /bin/sh
#

PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

# This can be changed as desired.
# The username does not need to exist anywhere in your system.

USERNAME=nobody

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
start)
    $PREFIX/sbin/identd $USERNAME && echo -n ' fakeidentd'
    ;;

stop)
    if [ -r /var/run/identd.pid ] ; then
    kill -9 `cat /var/run/identd.pid` >>/dev/null 2>&1
    rm -f /var/run/identd.pid
    fi
    ;;

*)
    echo "Usage: `basename $0` {start|stop}" >&2
    exit 64
    ;;
esac


