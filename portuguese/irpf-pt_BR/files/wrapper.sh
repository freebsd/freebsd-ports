#!/bin/sh
#
# Under a BSDL license. Copyright by Mario S F Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

export JAVA_VERSION

PREFIX="%%PREFIX%%"
# java
JAVA_VERSION="%%JAVA_VERSION%%"
JAVAVM="%%JAVAVM%%"
JAR_DIR="%%JAR_DIR%%"
JAR_FILES="%%JAR_FILES%%"
JAR_FILE="%%JAR_FILE%%"
# home
HOME_DIR=${HOME}/.irpf

configure_java_classpath () {
  if [ -z "${CLASSPATH}" ]
  then
        CLASSPATH=./irpf.jar:./jhall.jar
  else
        CLASSPATH=./irpf.jar:./jhall.jar:${CLASSPATH}
  fi
}

prepare_home_dir () {
  # create home dir staging area
  if [ ! -d ${HOME_DIR}/aplicacao/dados ]
  then
	mkdir -p ${HOME_DIR}/aplicacao/dados
  fi
  # link the jar files
  for jar in ${JAR_FILES}
  do
	rm -f ${HOME_DIR}/${jar} 2>/dev/null
	cp -f ${PREFIX}/${JAR_DIR}/${jar} ${HOME_DIR}/${jar} 2>/dev/null
  done
}

start_irpf () {
  cd ${HOME_DIR} &&
	exec ${JAVAVM} -jar ./${JAR_FILE} "${@}"
}

# always verify that home dir staging area is pristine
prepare_home_dir

# prepare java CLASSPATH
configure_java_classpath

start_irpf

# we should never get this far
exit 1
