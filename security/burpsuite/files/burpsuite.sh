#!/bin/sh
#
# $FreeBSD$
#

cd %%PATH%%
exec %%JAVA_CMD%% -jar -Xmx512m %%BURP%% "$@"
