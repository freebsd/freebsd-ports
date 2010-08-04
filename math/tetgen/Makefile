# New ports collection makefile for:	tetgen
# Date created:			16 December 2005
# Whom:				Pedro F. Giffuni
#
# $FreeBSD$
#

PORTNAME=	tetgen
PORTVERSION=	1.4.3
CATEGORIES=	math
MASTER_SITES=	http://tetgen.berlios.de/files/ \
		http://www.c-s.li/ports/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	c-s@c-s.li
COMMENT=	A Quality Tetrahedral Mesh Generator and Delaunay Triangulator

LICENSE_FILE=	${WRKDIR}/LICENSE

NO_CDROM=	Tetgen is for academic or personal use only

MAKE_JOBS_SAFE=	YES

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}
MAKEFILE=	makefile
ALL_TARGET=	tetgen tetlib

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/tetgen ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/tetgen.h ${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/libtet.a ${PREFIX}/lib
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example.poly ${EXAMPLESDIR}
.endif

regression-test:
	(cd ${INSTALL_WRKSRC} && ./tetgen -p example.poly )

.include <bsd.port.mk>
