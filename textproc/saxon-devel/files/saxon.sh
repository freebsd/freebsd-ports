#!/bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/textproc/saxon-devel/files/Attic/saxon.sh,v 1.4 2004-11-09 16:03:39 hq Exp $

IAM=`basename "$0"`

if [ "${IAM}" = "saxon-xquery" ]
then
	LAUNCHER_CLASS="net.sf.saxon.Query"
else
	LAUNCHER_CLASS="net.sf.saxon.Transform"
fi

SAXON_CLASSPATH=""
for jarfile in %%SAXON_JARS%%
do
	SAXON_CLASSPATH="${SAXON_CLASSPATH}:${jarfile}"
done

JAVAVM="%%JAVAVM%%" "%%LOCALBASE%%/bin/javavm" -classpath "${SAXON_CLASSPATH}" "${LAUNCHER_CLASS}" "$@"
