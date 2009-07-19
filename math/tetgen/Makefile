# New ports collection makefile for:	tetgen
# Date created:			16 December 2005
# Whom:				Pedro F. Giffuni
#
# $FreeBSD$
#

PORTNAME=	tetgen
PORTVERSION=	1.4.2
CATEGORIES=	math
MASTER_SITES=	http://www.wias-berlin.de/people/si/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Quality Tetrahedral Mesh Generator and Delaunay Triangulator

NO_CDROM=	Tetgen is for academic or personal use only

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}
MAKEFILE=	makefile
ALL_TARGET=	tetgen tetlib

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/tetgen ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/tetgen.h ${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/libtet.a ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example.poly ${EXAMPLESDIR}
.endif

regression-test:
	(cd ${INSTALL_WRKSRC} && ./tetgen -p example.poly )

.include <bsd.port.mk>
