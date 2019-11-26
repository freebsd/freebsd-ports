#!/bin/sh

PREFIX="%%PREFIX%%"
JAVAVM="%%JAVAVM%%"
JAR_DIR="%%JAR_DIR%%"
JAR_FILE="%%JAR_FILE%%"
DATADIR="%%DATADIR%%"
HOME_DIR=${HOME}/.frost
CLASSPATH="${PREFIX}/${JAR_DIR}/BCastle.jar:${PREFIX}/${JAR_DIR}/datechooser.jar:${PREFIX}/${JAR_DIR}/fec-native.jar:${PREFIX}/${JAR_DIR}/fecImpl.jar:${PREFIX}/${JAR_DIR}/frost.jar:${PREFIX}/${JAR_DIR}/genChkImpl.jar:${PREFIX}/${JAR_DIR}/gnu-regexp-1.1.4.jar:${PREFIX}/${JAR_DIR}/joda-time.jar:${PREFIX}/${JAR_DIR}/perst15.jar:${PREFIX}/${JAR_DIR}/skinlf.jar:${PREFIX}/${JAR_DIR}/skinlfFix.jar:${PREFIX}/${JAR_DIR}/mckoidb.jar:${PREFIX}/${JAR_DIR}/xercesImpl.jar:${PREFIX}/${JAR_DIR}/xml-apis.jar"

if [ ! -d ${HOME_DIR}/config ]
then
	mkdir -p ${HOME_DIR}/config
fi

ln -sf ${PREFIX}/${DATADIR}/boards.xml.default \
	${HOME_DIR}/config/boards.xml.default

if [ ! -d ${HOME_DIR}/themes ]
then
	mkdir -p ${HOME_DIR}/themes
	ln -sf ${PREFIX}/${DATADIR}/themepack.zip ${HOME_DIR}/themes/themepack.zip
fi

if [ ! -d ${HOME_DIR}/store ]
then
	mkdir -p ${HOME_DIR}/store
	ln -sf ${PREFIX}/${DATADIR}/applayerdb.conf \
		${HOME_DIR}/store/applayerdb.conf
fi

ln -sf ${PREFIX}/${DATADIR}/aquathemepack.zip \
	${HOME_DIR}/themes/aquathemepack.zip

cd ${HOME_DIR} &&
	exec ${JAVAVM} -cp $CLASSPATH frost.Frost "${@}"
