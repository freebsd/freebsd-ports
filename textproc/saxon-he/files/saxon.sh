#!/bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/textproc/saxon-he/files/Attic/saxon.sh,v 1.3 2004-10-27 16:50:43 hq Exp $

IAM=`basename "$0"`

if [ "${IAM}" = "saxon-xquery" ]
then
	LAUNCHER_CLASS="net.sf.saxon.Query"
else
	LAUNCHER_CLASS="net.sf.saxon.Transform"
fi

JAVAVM=%%JAVAVM%% %%LOCALBASE%%/bin/javavm -classpath "`%%LOCALBASE%%/bin/classpath`" ${LAUNCHER_CLASS} $@
