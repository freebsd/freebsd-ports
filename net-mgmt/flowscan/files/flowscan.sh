# rc script for flowscan
# Andreas Klemm <andreas@FreeBSD.org>, So  25 Mär 2001 12:46:10 CEST
# $FreeBSD$

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

bindir=${PREFIX}/var/db/flows/bin
logfile=${PREFIX}/var/db/flows/flowscan.log
perl=/usr/bin/perl
scandir=${PREFIX}/var/db/flows

case "$1" in
'start')
	cd ${scandir} \
	&& ${perl} ${bindir}/flowscan \
		>>${logfile} 2>&1 </dev/null \
		>/dev/null
	;;
 
'stop')
	killall flowscan
	;;
esac
