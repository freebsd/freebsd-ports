#!/bin/sh

PREFIX="%%PREFIX%%"
JAVAVM="%%JAVAVM%%"
JAR_DIR="%%JAR_DIR%%"
JAR_FILE="%%JAR_FILE%%"
SHARE_DIR="%%SHARE_DIR%%"
HOME_DIR=${HOME}/.frost
CLASSPATH="${PREFIX}/${JAR_DIR}/${JAR_FILE}:${PREFIX}/${JAR_DIR}/fecImpl.jar:${PREFIX}/${JAR_DIR}/genChkImpl.jar:${PREFIX}/${JAR_DIR}/xercesImpl.jar:${PREFIX}/${JAR_DIR}/xml-apis.jar:${PREFIX}/${JAR_DIR}/xmlParserAPIs.jar:$CLASSPATH"

if [ ! -d ${HOME_DIR}/config ]
then
	mkdir -p ${HOME_DIR}/config
fi

if [ ! -e ${HOME_DIR}/config/boards.xml.default ]
then
	cp ${PREFIX}/${SHARE_DIR}/boards.xml.default ${HOME_DIR}/config/
fi

cd ${HOME_DIR} &&
	exec ${JAVAVM} -cp $CLASSPATH frost.frost "${@}"
