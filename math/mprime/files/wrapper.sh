#!/bin/sh

PREFIX="%%PREFIX%%"
PROGRAM="${0}"
DIRNAME=${HOME}/.mprime

if [ ! -d ${DIRNAME} ]
then
	mkdir -p ${DIRNAME}
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
