# New ports collection makefile for:	UMFPACK
# Version required:	2.2
# Date created:         5 Nov 97
# Whom:                 Pedro Giffuni <giffunip@asme.org>
#
# $Id: Makefile,v 1.1.1.1 1998/07/11 18:20:27 steve Exp $
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
	${GZIP_CMD} ${WRKSRC}/README
	${INSTALL_DATA} ${WRKSRC}/README.gz ${PREFIX}/share/doc/umfpack
.endif
.include <bsd.port.mk>
