#!/bin/sh

PREFIX="%%PREFIX%%/bin"
PROGRAM="${0}"
DIRNAME=${HOME}/.amphetadesk
PERL="%%PERL%%"
DATADIR="%%DATADIR%%"

if [ ! -d ${DIRNAME} ]
then
	mkdir -p ${DIRNAME}
fi

echo " ${*} " | grep " \-createdironly " ||
{
	cd ${DIRNAME} &&
	echo Running under ${DIRNAME} &&
	mkdir -p data/lists &&
	ln -sf ${PREFIX}/${PROGRAM##*/}-real ${PROGRAM##*/} &&
	if [ -d "${DATADIR}/lists" ]; then
		cp -n ${DATADIR}/lists/* data/lists
        fi &&
	exec ${PERL} ./${PROGRAM##*/} "${@}" ||
	echo PROBLEM. Cannot create directory ${DIRNAME}, make sure you have the proper permissions to create it and try again
}
