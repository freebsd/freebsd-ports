#!/bin/sh

PREFIX="%%PREFIX%%"
JAVAVM="%%JAVAVM%%"
JAR_DIR="%%JAR_DIR%%"
JAR_FILE=xnap.jar

${JAVAVM} -jar ${PREFIX}/${JAR_DIR}/${JAR_FILE} "${@}"
