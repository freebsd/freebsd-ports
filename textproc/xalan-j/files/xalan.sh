#!/bin/sh

export CLASSPATH=`%%LOCALBASE%%/bin/classpath`:%%JAVAJARDIR%%/xalan.jar
exec %%LOCALBASE%%/bin/javavm org.apache.xalan.xslt.Process $@
