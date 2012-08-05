# New ports collection makefile for:	tetgen
# Date created:			16 December 2005
# Whom:				Pedro F. Giffuni
#
# $FreeBSD$
#

PORTNAME=	tetgen
PORTVERSION=	1.4.3.20110119
CATEGORIES=	math
MASTER_SITES=	http://wias-berlin.de/software/tetgen/files/
DISTNAME=	${PORTNAME}${PORTVERSION:R}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Quality Tetrahedral Mesh Generator and Delaunay Triangulator

LICENSE_FILE=	${WRKDIR}/LICENSE

NO_CDROM=	Tetgen is for academic or personal use only

OPTIONS_DEFINE=	EXAMPLES

MAKEFILE=	makefile
ALL_TARGET=	tetgen tetlib
MAKE_JOBS_SAFE=	yes

PORTEXAMPLES=	example.poly
PLIST_FILES=	bin/tetgen include/tetgen.h lib/libtet.a

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tetgen ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tetgen.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libtet.a ${PREFIX}/lib
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example.poly ${EXAMPLESDIR}
.endif

regression-test:
	(cd ${INSTALL_WRKSRC} && ./tetgen -p example.poly )

.include <bsd.port.mk>
