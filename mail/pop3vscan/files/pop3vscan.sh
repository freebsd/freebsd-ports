#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

user=pop3vscan
scanner=${PREFIX}/bin/uvscan
virusregexp="^[[:space:]]*Found( the|:)[[:space:]]*(.*)[[:space:]]*(|virus[^a-z.]*)$/2"
template=${PREFIX}/etc/pop3vscan.mail
viruscode=13

case "$1" in
    start)
    echo -n "Starting POP3VScan"
    ${PREFIX}/sbin/pop3vscan --user=${user} --scanner=${scanner} --virusregexp="${virusregexp}" --template=${template} --viruscode=${viruscode} || exit 1
    ;;
    stop)
    echo -n "Shutting down POP3VScan"
    kill `cat /var/run/pop3vscan.pid 2>/dev/null` &>/dev/null || exit 1
    ;;
    reload|restart)
    $0 stop && sleep 1 &&  $0 start || exit 1
    ;;
    *)
    echo "Usage: $0 {start|stop|reload|restart}"
    exit 1
esac

exit 0
