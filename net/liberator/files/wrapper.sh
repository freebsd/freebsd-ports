#!/bin/sh

PREFIX="%%PREFIX%%"
PROGRAM="${0}"
DATADIR="%%DATADIR%%"
MIME_FILE=liber_mimetypes

if [ ! -f ${MIME_FILE} ]
then
	cp -f ${PREFIX}/${DATADIR}/${MIME_FILE} \
		${HOME}/.${MIME_FILE}
fi

exec ${PREFIX}/bin/${PROGRAM##*/}-real "${@}"
