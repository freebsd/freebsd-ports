#!/bin/sh

PREFIX="%%PREFIX%%"
JAVAVM="%%JAVAVM%%"
JAR_DIR="%%JAR_DIR%%"
CLASSPATH="${PREFIX}/${JAR_DIR}/converter.jar"

exec ${JAVAVM} -cp ${CLASSPATH} converter
