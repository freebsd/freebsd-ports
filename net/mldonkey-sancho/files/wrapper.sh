#!/bin/sh
#
# Under a BSDL license. Copyright by Mario S F Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

export JAVA_VERSION
export JAVA_OS

PREFIX="%%PREFIX%%"
# java
JAVAVM="%%JAVAVM%%"
JAVA_VERSION="%%JAVA_VERSION%%"
JAVA_OS="%%JAVA_OS%%"
JAVAJARDIR="%%JAVAJARDIR%%"
# classpath
CLASSPATH="%%CLASSPATH%%"
# eclipse libs
JAVALIBPATH="%%JAVALIBPATH%%"

exec ${JAVAVM} "-Djava.library.path=${JAVALIBPATH}" -cp "${CLASSPATH}" \
	sancho.core.Sancho  "${@}"
