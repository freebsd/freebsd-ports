# New ports collection makefile for:	taucs
# Date created:		5 July 2003
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	taucs
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.tau.ac.il/~stoledo/taucs/${PORTVERSION}/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library of sparse linear solvers

BUILD_DEPENDS=	${LOCALBASE}/lib/libf77blas.a:${PORTSDIR}/math/atlas \
		${LOCALBASE}/lib/liblapack.a:${PORTSDIR}/math/lapack \
		${LOCALBASE}/lib/libmetis.a:${PORTSDIR}/math/metis

NO_WRKSUBDIR=	yes
HAS_CONFIGURE=	yes
MAKEFILE=	makefile
ALL_TARGET=

.include <bsd.port.pre.mk>

post-configure:
	cd ${WRKSRC}; ${PATCH} <${FILESDIR}/extra-patch-build-FreeBSD-makefile

do-install:
	@${INSTALL_DATA} ${WRKSRC}/lib/FreeBSD/libtaucs.a ${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/build/FreeBSD/*.h ${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/src/*.h ${PREFIX}/include
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/FreeBSD/direct ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/FreeBSD/iter ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
