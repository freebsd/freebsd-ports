#!/bin/sh

export JAVA_VERSION

PREFIX="%%PREFIX%%"
JAVA_VERSION="%%JAVA_VERSION%%"
JAVAVM="%%JAVAVM%%"
JAR_DIR="%%JAR_DIR%%"
JAR_FILE="%%JAR_FILE%%"
SHARE_DIR="%%SHARE_DIR%%"
HOME_DIR=${HOME}/.frost
CLASSPATH="${PREFIX}/${JAR_DIR}/BCastle.jar:${PREFIX}/${JAR_DIR}/fecImpl.jar:${PREFIX}/${JAR_DIR}/frost.jar:${PREFIX}/${JAR_DIR}/genChkImpl.jar:${PREFIX}/${JAR_DIR}/jocache.jar:${PREFIX}/${JAR_DIR}/mailapi.jar:${PREFIX}/${JAR_DIR}/skinlf.jar:${PREFIX}/${JAR_DIR}/skinlfFix.jar:${PREFIX}/${JAR_DIR}/smtp.jar:${PREFIX}/${JAR_DIR}/xercesImpl.jar:${PREFIX}/${JAR_DIR}/xml-apis.jar:$CLASSPATH"

if [ ! -d ${HOME_DIR}/config ]
then
	mkdir -p ${HOME_DIR}/config
fi

if [ ! -e ${HOME_DIR}/config/boards.xml.default ]
then
	cp ${PREFIX}/${SHARE_DIR}/boards.xml.default ${HOME_DIR}/config/
fi

if [ ! -d ${HOME_DIR}/themes ]
then
	mkdir -p ${HOME_DIR}/themes
fi

if [ ! -e ${HOME_DIR}/themes/themepack.zip ]
then
	cp ${PREFIX}/${SHARE_DIR}/themepack.zip ${HOME_DIR}/themes/
fi

cd ${HOME_DIR} &&
	exec ${JAVAVM} -cp $CLASSPATH frost.frost "${@}"
