#!/bin/sh
#
# Under a BSDL license. Copyright by Mario S F Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

export JAVA_VERSION

PREFIX="%%PREFIX%%"
# java
JAVA_VERSION="%%JAVA_VERSION%%"
JAVAVM_CALL="%%JAVAVM%%"
JAVAJARDIR="%%JAVAJARDIR%%"
JAR_FILES="%%JAR_FILES%%"
JAR_START="%%JAR_START%%"
# data
DATA_DIR="%%DATA_DIR%%"
SEED_FILE=seednodes.ref
# home
HOME_DIR=${HOME}/.freenet
CONFIG_FILE=freenet.conf

configure_freenet () {
  echo "Configuring FreeNet node"
  cd ${HOME_DIR} &&
  	${JAVAVM_CALL} -jar ./${JAR_START} freenet.node.Main --config "${@}" 
}

configure_java_classpath () {
  if [ -z "${CLASSPATH}" ]; then
	CLASSPATH=./freenet.jar:./freenet-ext.jar
  else
	CLASSPATH=./freenet.jar:./freenet-ext.jar:${CLASSPATH}
  fi
}

display_usage () {
  echo "Usage: ${0} [-h] [-c] [-i|-o]"
  echo 'Options:'
  echo '  -h  Display this help message'
  echo '  -c  Configure FreeNet node'
  echo '  -i  Start a FreeNet node'
  echo '  -o  Stop a FreeNet node'
  echo ''
}

prepare_configure_freenet () {
  # do we have a config file?
  if [ ! -f ${HOME_DIR}/${CONFIG_FILE} ]; then
	# add basic information prior to configuration
	echo > ${HOME_DIR}/${CONFIG_FILE}

	# select listenPort randomly
	if [ -n "${RANDOM}" ]
	then
		DEFLP=$((${RANDOM}%30000+2000))
	else
		echo "no random in shell, enter a FNP port number + <ENTER>"
		read DEFLP
	fi
	echo "listenPort=${DEFLP}" >> ${HOME_DIR}/${CONFIG_FILE}

	# point to seednodes file
	echo 'seedNodes=seednodes.ref' >> ${HOME_DIR}/${CONFIG_FILE}

	# tell FreeNet to request configuration procedure
	CONFIGURE=yes
  fi
}

prepare_home_dir () {
  # create home dir staging area
  if [ ! -d ${HOME_DIR} ]
  then
	mkdir -p ${HOME_DIR}
  fi
  # copy a seed file if none exists
  if [ ! -f ${HOME_DIR}/${SEED_FILE} ]
  then
	rm -f ${HOME_DIR}/${SEED_FILE}
	cp -f ${PREFIX}/${DATA_DIR}/${SEED_FILE} ${HOME_DIR}/${SEED_FILE}
	# avoid unnecessary reseeding
	touch -t "197001011200" ${HOME_DIR}/${SEED_FILE}
  fi
  # link the jar files
  for jar in ${JAR_FILES}
  do
	ln -sf ${PREFIX}/${JAVAJARDIR}/${jar} ${HOME_DIR}/${jar}
  done
}

start_freenet () {
  echo "Starting FreeNet node"
  cd ${HOME_DIR} &&
	nice -10 ${JAVAVM_CALL} -jar ./${JAR_START} "${@}" &
  echo $! > ${HOME_DIR}/freenet.pid
  exit 0
}

stop_freenet () {
  if [ -f ${HOME_DIR}/freenet.pid ]; then
	echo "Stopping FreeNet node"
	cd ${HOME_DIR} &&
		exec kill `cat freenet.pid` &
  else
	echo "Cannot find FreeNet node"
	echo "Where is the ${HOME_DIR}/freenet.pid file?"
  fi
}

# we require at least one command line parameter
if [ $# -lt 1 ]; then
	display_usage
	exit 1
fi

# parse command line parameters
while getopts "chio" COMMAND_LINE_ARGUMENT ; do
  case "${COMMAND_LINE_ARGUMENT}" in
  c)
	CONFIGURE=yes
	;;
  h)
	display_usage
	exit 0
	;;
  i)
	START=yes
	unset STOP
	;;
  o)
	STOP=yes
	unset START
	;;
  *)
	display_usage
	exit 1
	;;
  esac
done

# always verify that home dir staging area is pristine
prepare_home_dir

# check for proper configuration
prepare_configure_freenet

# prepare java CLASSPATH
configure_java_classpath

if [ -n "${CONFIGURE}" ]; then
  configure_freenet
fi

if [ -n "${START}" ]; then
  start_freenet
fi

if [ -n "${STOP}" ]; then
  stop_freenet
fi

# we should never get this far
exit 1
