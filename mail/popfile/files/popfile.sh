#!/bin/sh
#
# $FreeBSD$
#
export POPFILE_ROOT=%%DATADIR%%
export POPFILE_USER=${HOME}/.popfile

mkdir -p ${POPFILE_USER}
cd ${POPFILE_USER}
%%DATADIR%%/popfile.pl >/dev/null 2>&1 &
