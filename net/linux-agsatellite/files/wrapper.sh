#!/bin/sh

PREFIX="%%PREFIX%%"
PROGRAM="${0}"

if [ ! -d ${HOME}/.agsatellite ]
then
	mkdir -p ${HOME}/.agsatellite
fi

if [ ! -h ${HOME}/.agsatellite/${PROGRAM##*/} ]
then
	ln -sf ${PREFIX}/bin/${PROGRAM##*/}-real ${HOME}/.agsatellite/${PROGRAM##*/}
fi

echo " ${*} " | grep " \-createdironly " ||
{
	cd ${HOME}/.agsatellite &&
	echo Running Audio Galaxy Satellite under ${HOME}/.agsatellite &&
	echo Create both account.txt and shares.txt files under ${HOME}/.agsatellite &&
	exec ./${PROGRAM##*/} ${*} ||
	echo PROBLEM. Cannot create directory ${HOME}/.agsatellite, make sure you have the proper permissions to create itnd try again
}
