#!/bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/net/netatalk-devel/files/Attic/netatalk.sh,v 1.2 2004-06-06 02:25:46 marcus Exp $
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
	%%PREFIX%%/sbin/cnid_metad
	%%PREFIX%%/sbin/afpd -s %%PREFIX%%/etc/AppleVolumes.system \
		-f %%PREFIX%%/etc/AppleVolumes.default
	[ -x %%PREFIX%%/sbin/timelord ] && %%PREFIX%%/sbin/timelord
	;;
stop)
	killall timelord
	killall afpd
	killall cnid_metad
	killall papd
	killall atalkd
	;;
*)
	echo "Usage: $0: [ start | stop ]" 2>&1
	exit 65
	;;
esac
