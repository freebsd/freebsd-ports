#!/bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/textproc/saxon-he/files/Attic/saxon.sh,v 1.2 2004-07-17 08:19:44 glewis Exp $

export CLASSPATH=`%%PREFIX%%/bin/classpath`
JAVAVM=%%JAVAVM%% javavm -jar %%JAVAJARDIR%%/saxon8.jar $@
