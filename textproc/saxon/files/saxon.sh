#!/bin/sh
#
# $FreeBSD$

export CLASSPATH=`%%PREFIX%%/bin/classpath`
javavm -jar %%JAVAJARDIR%%/saxon.jar $@
