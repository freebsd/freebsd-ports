#!/bin/sh
#
# $FreeBSD$
# 
if ! test -x %%PREFIX%%/libexec/antivirus
then
	exit 0
fi
case "$1" in
start)
	rm -f %%ANTIVIRUS%%/antivirus.sock %%ANTIVIRUS%%/run/antivirus.pid
	%%PREFIX%%/libexec/antivirus -p local:%%ANTIVIRUS%%/antivirus.sock &
	echo -n ' antivirus'
	;;
stop)
	if test -r %%ANTIVIRUS%%/run/antivirus.pid
	then
		kill `head -1 %%ANTIVIRUS%%/run/antivirus.pid`
	else
		echo " antivirus: not running" 2>&1
	fi
	rm -f %%ANTIVIRUS%%/run/antivirus.pid
	;;
*)
	echo "Usage: ${0##*/}: { start | stop }" >&2
	exit 64
	;;
esac
