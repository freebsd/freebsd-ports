#!/bin/sh
# $FreeBSD$

export CLASSPATH=%%PREFIX%%/share/java/classes/xt.jar:%%PREFIX%%/share/java/classes/xml4j.jar:${CLASSPATH}

java -Dcom.jclark.xsl.sax.parser=com.ibm.xml.parsers.SAXParser com.jclark.xsl.sax.Driver $*

