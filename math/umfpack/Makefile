# New ports collection makefile for:	UMFPACK
# Date created:		5 Nov 97
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	umfpack
PORTVERSION=	4.1
CATEGORIES=	math
MASTER_SITES=	http://www.cise.ufl.edu/research/sparse/umfpack/v${PORTVERSION}/
DISTNAME=	UMFPACKv${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unsymmetric-pattern MultiFrontal Package

BROKEN=		Does not install

BUILD_DEPENDS=	${LOCALBASE}/lib/libcblas.a:${PORTSDIR}/math/atlas

WRKSRC=		${WRKDIR}/${DISTNAME}/UMFPACK
ALL_TARGET=	lib

post-extract:
	${CP} ${FILESDIR}/Make.freebsd ${WRKDIR}/${DISTNAME}/AMD/Make

do-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/AMD/Lib/libamd.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/Lib/libumfpack.a ${PREFIX}/lib

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/AMD/Doc/*.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${GZIP_CMD} ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/*.pdf  ${DOCSDIR}
	${CP} -R ${WRKDIR}/${DISTNAME}/Papers ${DOCSDIR}
.endif

.include <bsd.port.mk>
