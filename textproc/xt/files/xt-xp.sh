#!/bin/sh
# $FreeBSD$

export CLASSPATH=%%PREFIX%%/share/java/classes/xt.jar:%%PREFIX%%/share/java/classes/xp-0.5.jar:%%PREFIX%%/share/java/classes/sax.jar:${CLASSPATH}

java com.jclark.xsl.sax.Driver $*
