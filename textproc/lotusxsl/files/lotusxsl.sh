#!/bin/sh
# $FreeBSD$

export CLASSPATH=%%PREFIX%%/share/java/classes/xml4j.jar:%%PREFIX%%/share/java/classes/lotusxsl.jar:${CLASSPATH}

java com.lotus.xsl.xml4j2dom.XML4JLiaison4dom $* -v

# -xsl ??.xsl -in ??.xml -out ??.html
