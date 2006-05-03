# New ports collection makefile for:	Chaco
# Date created:         26 April 2006
# Whom:                 Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	chaco
PORTVERSION=	2.2
CATEGORIES=	math
MASTER_SITES=	http://www.cs.sandia.gov/downloads/papers/bahendr/	\
		http://bsd1.csme.ru/myports/	\
		http://bsd2.csme.ru/myports/	\
		http://bsd3.csme.ru/myports/
DISTNAME=	Chaco-${PORTVERSION}

MAINTAINER=	giffunip@asme.org
COMMENT=	Software for Partitioning Graphs

WRKSRC=		${WRKDIR}/${DISTNAME}/code
ALL_TARGET=

do-configure:
	@${REINPLACE_CMD} -e 's+@CFLAGS@+${CFLAGS}+g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/exec/chaco ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/exec/libchaco.a ${PREFIX}/lib
.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/*.ps ${DOCSDIR}
	${GZIP_CMD} ${DOCSDIR}/*.ps
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/exec/*.graph ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/exec/*.coords ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
