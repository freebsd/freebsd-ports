#!/bin/sh
#
# $FreeBSD$

exec %%JAVA%% -classpath "`%%LOCALBASE%%/bin/classpath`" nux.xom.tests.ValidationCommand $*
