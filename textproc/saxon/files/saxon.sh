#!/bin/sh
#
# $FreeBSD$

SAXON_CLASSPATH=""
for jarfile in %%SAXON_JARS%%
do
	SAXON_CLASSPATH="${SAXON_CLASSPATH}:${jarfile}"
done

"%%LOCALBASE%%/bin/javavm" -classpath "${SAXON_CLASSPATH}" com.icl.saxon.StyleSheet "$@"
