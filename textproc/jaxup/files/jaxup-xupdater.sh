#!/bin/sh
#
# $FreeBSD$

JAVA_VERSION="%%JAVA_VERSION%%" %%LOCALBASE%%/bin/java -cp "`"%%LOCALBASE%%/bin/classpath"`:%%DATADIR%%/jaxup-xupdater.jar" "DOMXUpdater" "$@"
