#! /bin/sh

# rc script for flowscan
# Andreas Klemm <andreas@FreeBSD.org>, So  25 Mär 2001 12:46:10 CEST
# $FreeBSD$

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

awk=/usr/bin/awk
bindir=$PREFIX/var/db/flows/bin
grep=/usr/bin/grep
kill=/bin/kill
logfile=$PREFIX/var/db/flows/flowscan.log
perl=/usr/bin/perl
scandir=$PREFIX/var/db/flows

case "$1" in
'start')
	[ -x $bindir/flowscan ] \
	&& ( cd $scandir \
	&& $perl $bindir/flowscan \
		>> $logfile 2>&1 </dev/null \
		> /dev/null & ) \
	&& echo -n " flowscan"
	;;
 
'stop')
	pid=`ps -ax | $grep "$perl $bindir/flowscan" | $awk '{ print $1 }'`
	if [ -n "$pid" ]; then
		echo "killing flowscan"
		$kill $pid
	fi
	;;
esac

exit 0
