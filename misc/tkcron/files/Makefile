#
# $FreeBSD$
#

BINDIR=		${PREFIX}/bin
WISHDIR?=	${BINDIR}

all:		tkcron

tkcron:	
	cp tkcron.tcl tkcron

install:	all
	install ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} tkcron ${BINDIR}

.include <bsd.own.mk>
