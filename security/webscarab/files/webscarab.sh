#!/bin/sh
#
# $FreeBSD$
#

TEST=`/usr/bin/basename $0`
OPTIONS="-DWebScarab.lite=false"

if [ "${TEST}" = "webscarab_lite" ]; then
	OPTIONS=""
fi


cd %%PATH%%
exec %%JAVA_CMD%% ${OPTIONS} -jar -Xmx256m %%WEBSCARAB%% "$@"
