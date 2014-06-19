#!/bin/sh
#
# $FreeBSD$
#
case "${HOME}" in
"")
	export POPFILE_USER_DEFAULT=/var/db/popfile
	;;
*)
	export POPFILE_USER_DEFAULT="${HOME}/.popfile"
	;;
esac

die()
{
	echo "$1"
	exit 1
}

export POPFILE_ROOT=%%DATADIR%%
export POPFILE_USER=${POPFILE_USER:-${POPFILE_USER_DEFAULT}}

mkdir -p "${POPFILE_USER}" || die "mkdir ${POPFILE_USER} failed"
cd "${POPFILE_USER}"
%%DATADIR%%/popfile.pl >/dev/null 2>&1 &
