#!/bin/sh

PREFIX="%%PREFIX%%"
PROGRAM="${0}"
DIRNAME="${HOME}/.mute-net/%%INTERFACE%%"
DIR_FILES="${DIRNAME}/files"
DIR_SETTINGS_ORIGINAL="%%DATADIR%%/settings"
DIR_SETTINGS="${DIRNAME}/settings"

if [ ! -d ${DIRNAME} ]
then
	mkdir -p ${DIRNAME}
fi

if [ ! -d ${DIR_FILES} ]
then
	mkdir -p ${DIR_FILES}
fi

if [ ! -d ${DIR_SETTINGS} ]
then
	mkdir -p "${DIR_SETTINGS}"
	cp -R "${DIR_SETTINGS_ORIGINAL}/." "${DIR_SETTINGS}"
fi

if [ ! -h ${DIRNAME}/${PROGRAM##*/} ]
then
	ln -sf ${PREFIX}/bin/${PROGRAM##*/}-real ${DIRNAME}/${PROGRAM##*/}
fi

echo " ${*} " | grep " \-createdironly " ||
{
	cd ${DIRNAME} &&
	echo Running under ${DIRNAME} &&
	exec ./${PROGRAM##*/} "${@}" ||
	echo PROBLEM. Cannot create directory ${DIRNAME}, make sure you have the proper permissions to create it and try again
}
