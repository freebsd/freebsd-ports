#! /bin/sh

case $1 in
start)
	[ -x /usr/local/sbin/pptpd ] && /usr/local/sbin/pptpd && echo -n ' pptpd'
	;;
stop)
	killall pptpd && echo -n ' pptpd'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
