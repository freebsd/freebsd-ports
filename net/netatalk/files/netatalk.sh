#!/bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/net/netatalk/files/Attic/netatalk.sh,v 1.1 2001-05-18 20:00:29 dinoex Exp $
#
# AppleTalk daemons. Make sure not to start atalkd in the background:
# its data structures must have time to stablize before running the
# other processes.
#
if ! test -x %%PREFIX%%/sbin/atalkd
then
#	exit 0
fi
HOSTNAME=`hostname|sed 's/\..*$//'`
case $1 in
start)
	echo -n ' netatalk'
	%%PREFIX%%/sbin/atalkd
	%%PREFIX%%/bin/nbprgstr -p 4 ${HOSTNAME}:Workstation &
	%%PREFIX%%/bin/nbprgstr -p 4 ${HOSTNAME}:netatalk &
	%%PREFIX%%/sbin/papd
	%%PREFIX%%/sbin/afpd -s %%PREFIX%%/etc/AppleVolumes.system \
		-f %%PREFIX%%/etc/AppleVolumes.default
	;;
stop)
	killall afpd
	killall papd
	killall atalkd
	;;
*)
	echo "Usage: $0: [ start | stop ]" 2>&1
	exit 65
	;;
esac
