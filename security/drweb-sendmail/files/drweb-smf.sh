#!/bin/sh
#
# $FreeBSD$

drwebfilter='!!PREFIX!!/sbin/drweb-smf'

case "$1" in
start)
	if [ -x $drwebfilter ]; then
	    echo -n ' drweb-smf'
	    $drwebfilter -u/var/run/drwebd -m/var/run/drweb-smf.sock -a/var/spool/drweb_infected -f/var/spool/drweb-smf -r -x -h -l -ba -gpostmaster -epostmaster
	fi
	;;
stop)
	/usr/bin/killall drweb-smf
	/bin/rm -f /var/run/drweb-smf.sock
	echo -n ' drweb-smf'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
