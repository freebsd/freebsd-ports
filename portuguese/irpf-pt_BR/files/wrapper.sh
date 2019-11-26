#!/bin/sh
#
# Under a BSDL license. Copyright by Mario S F Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PREFIX="%%PREFIX%%"
# java
JAVAVM="%%JAVAVM%%"
JAR_DIR="%%JAR_DIR%%"
JAR_FILES="%%JAR_FILES%%"
JAR_FILE="%%JAR_FILE%%"
# home
HOME_DIR=${HOME}/.irpf

prepare_home_dir () {
  # create home dir staging area
  if [ ! -d ${HOME_DIR}/aplicacao/dados ]
  then
	mkdir -p ${HOME_DIR}/aplicacao/dados
  fi
  # create the lib dir
  if [ ! -d ${HOME_DIR}/lib ]
  then
	mkdir -p ${HOME_DIR}/lib 2>/dev/null
  fi
  # link the jar file
  rm -f ${HOME_DIR}/${JAR_FILE} 2>/dev/null
  cp -f ${PREFIX}/${JAR_DIR}/${JAR_FILE} ${HOME_DIR}/${JAR_FILE} 2>/dev/null
  # link the jar files
  for jar in ${JAR_FILES}
  do
	rm -f ${HOME_DIR}/lib/${jar} 2>/dev/null
	cp -f ${PREFIX}/${JAR_DIR}/${jar} ${HOME_DIR}/lib/${jar} 2>/dev/null
  done
}

start_irpf () {
  cd ${HOME_DIR} &&
	${JAVAVM} -jar ./${JAR_FILE} "${@}"
}

clean_home_dir () {
  # remove the data files
  for data in ${DATA_FILES}
  do
	if [ -f ${HOME_DIR}/${data} ]
	then
		rm -f ${HOME_DIR}/${data} 2>/dev/null
	fi
  done
  # remove the jar file
  rm -f ${HOME_DIR}/${JAR_FILE} 2>/dev/null
  # remove the jar files
  for jar in ${JAR_FILES}
  do
	if [ -f ${HOME_DIR}/lib/${jar} ]
	then
		rm -f ${HOME_DIR}/lib/${jar} 2>/dev/null
	fi
  done
  # remove the lib dir
  if [ -d ${HOME_DIR}/lib ]
  then
	rmdir ${HOME_DIR}/lib 2>/dev/null
  fi
}

# always verify that home dir staging area is pristine
prepare_home_dir

start_irpf

# remove jars
clean_home_dir
