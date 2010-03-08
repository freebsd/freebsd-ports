#!/bin/sh
#
# $FreeBSD$
#

cd %%PATH%%
exec %%JAVA_CMD%% -jar -Xmx256m %%BURP%% "$@"
