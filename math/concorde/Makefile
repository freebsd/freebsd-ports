# New ports collection makefile for:	concorde
# Date created:				3 July 2000
# Whom:					dbader@eece.unm.edu
#
# $FreeBSD$
#

PORTNAME=	concorde
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.caam.rice.edu/pub/software/keck/
DISTNAME=	co991215
EXTRACT_SUFX=	.tgz

MAINTAINER=	dbader@eece.unm.edu

WRKSRC=		${WRKDIR}/concorde

GNU_CONFIGURE=  yes

INCFILES=	bigguy.h combs.h config.h consec1.h cut.h cuttree.h \
		delaunay.h edgegen.h fmatch.h heldkarp.h kdtree.h \
		linkern.h localcut.h lp.h machdefs.h macrorus.h mlinkern.h \
		necklace.h pq.h pqsets.h profdata.h profrus.h tinytsp.h \
		tsp.h util.h verify.h

do-install:
	${INSTALL_DATA} ${WRKSRC}/concorde.a ${PREFIX}/lib/libconcorde.a
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 ${PREFIX}/include/concorde
	${INSTALL_DATA} ${WRKSRC}/concorde.h ${PREFIX}/include/concorde
.for f in ${INCFILES}
	${INSTALL_DATA} ${WRKSRC}/INCLUDE/${f} ${PREFIX}/include/concorde
.endfor

.include <bsd.port.mk>
