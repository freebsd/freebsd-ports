#!/bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/textproc/saxon-he/files/Attic/saxon.sh,v 1.1 2004-07-07 20:36:36 glewis Exp $

export CLASSPATH=`%%PREFIX%%/bin/classpath`
javavm -jar %%JAVAJARDIR%%/saxon8.jar $@
