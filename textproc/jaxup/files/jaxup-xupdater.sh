#!/bin/sh
#
# $FreeBSD$

JAVA_VERSION="1.3+" %%LOCALBASE%%/bin/java -cp "`"%%LOCALBASE%%/bin/classpath"`:%%DATADIR%%/jaxup-xupdater.jar" "DOMXUpdater" "$@"
