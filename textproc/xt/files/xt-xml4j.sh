#!/bin/sh
# $FreeBSD$

export CLASSPATH=%%PREFIX%%/share/java/classes/xt.jar:%%PREFIX%%/share/java/classes/xerces.jar:${CLASSPATH}

java -Dcom.jclark.xsl.sax.parser=org.apache.xerces.parsers.SAXParser com.jclark.xsl.sax.Driver $*
