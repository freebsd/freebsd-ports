#!/bin/sh
#
#	runs clamd and clamav-milter
#

case "$1" in
'start')
	rm -f /tmp/clamd /var/run/clmilter.sock
	%%PREFIX%%/sbin/clamd && echo -n " clamd"
	%%PREFIX%%/sbin/clamav-milter \
		--local \
		--outgoing \
		--max-children=50 \
		/var/run/clmilter.sock &
	echo -n " clamav-milter"
	;;
'stop')
	killall 'clamav-milter'
	echo -n " clamav-milter"
	killall 'clamd'
	echo -n " clamad"
	;;
*)
	echo "Usage: ${0##*/} { start | stop }"
	;;
esac

exit 0
