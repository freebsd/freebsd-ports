#
# $FreeBSD$
#

BINDIR=		${PREFIX}/bin
WISHDIR?=	${BINDIR}

all:		tkcron

tkcron:	
	sed -e "\:/usr/local/bin/wish: s;;${BINDIR}/wish8.2;g" tkcron.tcl > tkcron

install:	all
	install ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} tkcron ${BINDIR}

.include <bsd.own.mk>
