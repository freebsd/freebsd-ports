#!/bin/sh

PREFIX="%%PREFIX%%"
JAVAVM="%%JAVAVM%%"
JAR_DIR="%%JAR_DIR%%"
JAR_FILE="%%JAR_FILE%%"
HOME_DIR=${HOME}/.frost

if [ ! -d ${HOME_DIR} ]
then
	mkdir -p ${HOME_DIR}
fi

cd ${HOME_DIR} &&
	exec ${JAVAVM} -jar ${PREFIX}/${JAR_DIR}/${JAR_FILE} "${@}"
