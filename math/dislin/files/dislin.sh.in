#!/bin/sh
#
# Wrapper script for DISLIN binaries.
#
# $FreeBSD$
#

DISLIN=%%DISLIN_DIR%%
export DISLIN

self="${0##*/}"
program="${DISLIN}/bin/${self}"

if [ -x "${program}" ] ; then
	exec "${program}" "$@"
else
	echo "${self} does not seem to exist." 1>&2
	exit 1
fi
