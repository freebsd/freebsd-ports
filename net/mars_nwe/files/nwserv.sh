#!/bin/sh

PREFIX=/usr/local

PROG=${PREFIX}/sbin/nwserv

if [ x$1 = xstart ]; then
	(sleep 120;${PROG}) &
elif [ "x$1" = "xstop" ]; then
	${PROG} -k
fi
