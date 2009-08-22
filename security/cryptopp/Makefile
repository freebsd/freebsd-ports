# New ports collection makefile for:   cryptopp
# Date created:        18 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=		cryptopp
PORTVERSION=		5.6.0
CATEGORIES=		security
MASTER_SITES=		SF \
			http://www.cryptopp.com/

DISTNAME=		cryptopp${PORTVERSION:S/.//g}

MAINTAINER=		delphij@FreeBSD.org
COMMENT=		A free C++ class library of Cryptographic Primitives

NO_WRKSUBDIR=		yes
USE_ZIP=		yes
EXTRACT_BEFORE_ARGS=	-aq
USE_GMAKE=		yes
MAKE_JOBS_SAFE=		yes
MAKEFILE=		GNUmakefile

.if !defined(WITH_DEBUG)
CXXFLAGS+=	-DNDEBUG
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cryptest.exe ${PREFIX}/bin/cryptest
	${INSTALL_DATA} ${WRKSRC}/libcryptopp.a ${PREFIX}/lib
	${MKDIR} ${PREFIX}/include/cryptopp
	(for i in `${FIND} ${WRKSRC}/ -name '*.h' \
			-and -not -name 'dll.h' \
			-and -not -name 'resource.h'`; do \
		${INSTALL_DATA} $$i ${PREFIX}/include/cryptopp; \
	done)
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/cryptopp
	${CP} ${WRKSRC}/Readme.txt ${PREFIX}/share/doc/cryptopp/README
	${CP} ${WRKSRC}/License.txt ${PREFIX}/share/doc/cryptopp/License
.endif

.include <bsd.port.mk>
