#!/bin/sh
#
# $FreeBSD$
# 
if ! test -x %%PREFIX%%/libexec/noattach
then
	exit 0
fi
case $1 in
start)
	rm -f /var/run/noattach.pid
	%%PREFIX%%/libexec/noattach -p local:/var/run/noattach &&
	echo -n ' noattach'
	;;
stop)
	killall noattach
	rm -f /var/run/noattach.pid
	;;
*)
	echo "Usage: $0: [ start | stop ]" 2>&1
	exit 65
	;;
esac
