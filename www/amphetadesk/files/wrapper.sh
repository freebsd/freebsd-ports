#!/bin/sh
#
# $FreeBSD$
#
# Under a BSDL license. Copyright 2005. Mario S F Ferreira <lioux@FreeBSD.org>

PREFIX="%%PREFIX%%/bin"
PROGRAM="${0}"
DIRNAME="${HOME}/.amphetadesk"
PERL="%%PERL%%"
DATADIR="%%DATADIR%%"

PROGRAM_PIDFILE="${PIDFILE:-${DIRNAME}/${PROGRAM##*/}.pid}"

if [ `id -un` = root ]; then
  echo "PROBLEM. Running AmphetaDesk as root is not recommended."
  exit 1
fi

if [ -z "${HOME}" -o ! -d "${HOME}" ]
then
  echo "PROBLEM. User does not have a valid home directory [${HOME}]"
  exit 1
fi

if [ ! -d "${DIRNAME}/data/lists" ]
then
  mkdir -p "${DIRNAME}/data/lists"
fi

if [ ! -d "${DIRNAME}/data/lists" ]
then
  echo "PROBLEM. Cannot create directory ${DIRNAME}."
  echo "Make sure you have the proper permissions to create it and try again."
  exit 1
else
  ln -sf "${PREFIX}/${PROGRAM##*/}-real" "${DIRNAME}/${PROGRAM##*/}"
fi

#if [ -d "${DATADIR}/lists" ]; then
#  cp -n "${DATADIR}/lists/"* "${DIRNAME}/data/lists"
#fi

echo " ${*} " | grep " \-createdironly " ||
{
  echo "Running under ${DIRNAME}"
  cd "${DIRNAME}" &&
  {
    {
    env \
    DIRNAME="${DIRNAME}" \
    ${PERL} "./${PROGRAM##*/}" "${@}" ; 
    } &
  } &&
  echo $! > "${PROGRAM_PIDFILE}" &&
  exit 0 ||
  {
    echo "PROBLEM starting the application."
    exit 1
  }
}
