#! /bin/sh

# rc script for cflowd
# Andreas Klemm <andreas@FreeBSD.org>, So  25 Mär 2001 12:46:10 CEST
# $FreeBSD$

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

case "$1" in
'start')
	[ -x $PREFIX/sbin/cflowdmux -a -s $PREFIX/etc/cflowd.conf ] \
	&& $PREFIX/sbin/cflowdmux $PREFIX/etc/cflowd.conf \
	&& echo -n " cflowdmux"
	sleep 2
	[ -x $PREFIX/sbin/cflowd -a -s $PREFIX/etc/cflowd.conf ] \
	&& $PREFIX/sbin/cflowd $PREFIX/etc/cflowd.conf \
	&& echo -n " cflowd"
	sleep 2
	[ -x $PREFIX/sbin/cfdcollect -a -s $PREFIX/etc/cfdcollect.conf ] \
	&& $PREFIX/sbin/cfdcollect $PREFIX/etc/cfdcollect.conf \
	&& echo -n " cfdcollect"
	;;
 
'stop')
	for i in cfdcollect cflowd cflowdmux
	do
		sleep 2
		killall -15 $i && echo "graceful shutdown of $i"
	done
	;;
esac

exit 0
