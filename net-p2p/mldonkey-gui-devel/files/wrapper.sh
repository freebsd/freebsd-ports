#!/bin/sh

PREFIX="%%PREFIX%%/bin"
PROGRAM="${0}"
DIRNAME=${HOME}/.mldonkey

if [ ! -d ${DIRNAME} ]
then
	mkdir -p ${DIRNAME}
fi

echo " ${*} " | grep " \-createdironly " ||
{
	cd ${DIRNAME} &&
	echo Running under ${DIRNAME} &&
	exec ${PREFIX}/${PROGRAM##*/}-real "${@}" ||
	echo PROBLEM. Cannot create directory ${DIRNAME}, make sure you have the proper permissions to create it and try again
}
