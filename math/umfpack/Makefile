# New ports collection makefile for:	UMFPACK
# Version required:	2.2
# Date created:         5 Nov 97
# Whom:                 Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

DISTNAME=	umfpack2.2
PKGNAME=	umfpack-2.2
CATEGORIES=	math
MASTER_SITES=	http://netlib.bell-labs.com/netlib/linalg/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${PREFIX}/lib/libblas.a:${PORTSDIR}/math/blas

NO_CDROM=	'Must not be sold'
WRKSRC=         ${WRKDIR}/UMFPACK2.2
ALL_TARGET=	libumfpack.a

do-install:
	$(INSTALL_DATA) ${WRKSRC}/libumfpack.a ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/umfpack
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/umfpack
	${GZIP_CMD} ${PREFIX}/share/doc/umfpack/README
.endif

.include <bsd.port.mk>
