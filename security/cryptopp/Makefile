# New ports collection makefile for:   cryptopp
# Date created:        18 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=		cryptopp
PORTVERSION=		5.4
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE} \
			http://www.cryptopp.com/ \
			http://www.mirrors.wiretapped.net/security/cryptography/libraries/cryptolib/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		cryptopp${PORTVERSION:S/.//g}

MAINTAINER=		delphij@FreeBSD.org
COMMENT=		A free C++ class library of Cryptographic Primitives

NO_WRKSUBDIR=		yes
USE_ZIP=		yes
EXTRACT_BEFORE_ARGS=	-aq
USE_GMAKE=		yes
MAKEFILE=		GNUmakefile

pre-install:
	${STRIP_CMD} ${WRKSRC}/cryptest

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cryptest ${PREFIX}/bin
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
