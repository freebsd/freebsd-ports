#!/bin/sh

PREFIX="%%PREFIX%%"
CONFIG="%%CONFIG%%"
IMAGE="%%IMAGE%%"
PROGRAM="${0}"
DIRNAME=${HOME}/.mldonkey-serverspy

if [ ! -d ${DIRNAME} ]
then
	mkdir -p ${DIRNAME}
fi

if [ ! -h ${DIRNAME}/${PROGRAM##*/} ]
then
	ln -sf ${PREFIX}/bin/${PROGRAM##*/}-real ${DIRNAME}/${PROGRAM##*/}
fi

if [ ! -f ${DIRNAME}/${IMAGE} -o ! -h ${DIRNAME}/${IMAGE} ]
then
	ln -sf ${PREFIX}/share/mldonkey-serverspy/${IMAGE} \
		${DIRNAME}/${IMAGE}
fi

if [ ! -f ${DIRNAME}/${CONFIG} ]
then
	rm -f ${DIRNAME}/${CONFIG}
	cp -f ${PREFIX}/share/mldonkey-serverspy/${CONFIG} \
		${DIRNAME}/${CONFIG}

	echo Edit the configuration file ${DIRNAME}/${CONFIG} then run ${PROGRAM##*/} again.
else
	echo " ${*} " | grep " \-createdironly " ||
	{
		cd ${DIRNAME} &&
		echo Running under ${DIRNAME} &&
		exec ./${PROGRAM##*/} "${@}" ||
		echo PROBLEM. Cannot create directory ${DIRNAME}, make sure you have the proper permissions to create it and try again
	}
fi
