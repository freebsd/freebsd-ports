# New ports collection makefile for:	concorde
# Date created:				3 July 2000
# Whom:					dbader@ece.unm.edu
#
# $FreeBSD$
#

PORTNAME=	concorde
PORTVERSION=	20031219
CATEGORIES=	math parallel
MASTER_SITES=	http://www.tsp.gatech.edu/concorde/downloads/codes/src/
DISTNAME=	co031219
EXTRACT_SUFX=	.tgz

MAINTAINER=	dbader@ece.unm.edu
COMMENT=	Combinatorial Optimization package

WRKSRC=		${WRKDIR}/concorde

GNU_CONFIGURE=	yes
ALL_TARGET=	everything

INCFILES=	bigguy.h combs.h config.h consec1.h cut.h cuttree.h \
		delaunay.h edgegen.h fmatch.h heldkarp.h kdtree.h \
		linkern.h localcut.h lp.h machdefs.h macrorus.h mlinkern.h \
		necklace.h pq.h pqsets.h tinytsp.h \
		tsp.h util.h verify.h

BINFILES=	BIGGUY/bg_test COMBS/combtest CUT/lin_all CUT/mincut \
		EDGEGEN/edgegen FMATCH/fmatch HELDKARP/heldkarp KDTREE/kdtree \
		LINKERN/linkern LOCALCUT/checker LOCALCUT/first \
		LOCALCUT/localcut LOCALCUT/peeler LOCALCUT/peeler2 PQ/pqtest \
		TINY/tinytsp TOOLS/edg2len TOOLS/edgunion TOOLS/fconvert \
		TOOLS/killgrun TOOLS/prob2tsp TOOLS/showres TOOLS/tourchk \
		TOOLS/tourlen TSP/bosstell TSP/concorde TSP/cutserv \
		TSP/poolcat TSP/probserv TSP/test_tsp VERIFY/verify

do-install:
	${INSTALL_DATA} ${WRKSRC}/concorde.a ${PREFIX}/lib/libconcorde.a
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 ${PREFIX}/include/concorde
	${INSTALL_DATA} ${WRKSRC}/concorde.h ${PREFIX}/include/concorde
.for f in ${INCFILES}
	${INSTALL_DATA} ${WRKSRC}/INCLUDE/${f} ${PREFIX}/include/concorde
.endfor
	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755 ${PREFIX}/bin/concorde
.for f in ${BINFILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin/concorde
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/TINY/randtsp.awk ${PREFIX}/bin/concorde

.include <bsd.port.mk>
