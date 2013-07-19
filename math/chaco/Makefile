# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	chaco
PORTVERSION=	2.2
CATEGORIES=	math
MASTER_SITES=	http://www.cs.sandia.gov/downloads/papers/bahendr/ \
		http://bsd1.csme.ru/myports/ \
		http://bsd2.csme.ru/myports/ \
		http://bsd3.csme.ru/myports/
DISTNAME=	Chaco-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Software for partitioning graphs

USES=		gmake
MAKE_ARGS=	CFLAGS="${CFLAGS}"
ALL_TARGET=	#
WRKSRC=		${WRKDIR}/${DISTNAME}/code

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/exec/chaco ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/exec/libchaco.a ${PREFIX}/lib
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/*.ps ${DOCSDIR}
	${GZIP_CMD} ${DOCSDIR}/*.ps
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/exec/*.graph ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/exec/*.coords ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
