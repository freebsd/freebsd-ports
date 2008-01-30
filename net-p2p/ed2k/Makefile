# New ports collection makefile for:	ed2k hash tool
# Date created:				Mi  9 Nov 2005 06:52:38 CET
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	ed2k
PORTVERSION=	1.4
CATEGORIES=	net-p2p
MASTER_SITES=	http://www.sdalu.com/download/software/tools/
PKGNAMESUFFIX=	-hash${PKGNAMESUFFIX2}
DISTNAME=	ed2k.c
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Calculates 'eMule' hashes or producing ed2k:// file links

CONFILTCS=	aMule-*
WRKSRC=		${WRKDIR}
MAKEFILE=	/dev/null
ALL_TARGET=	ed2k
PLIST_FILES=	bin/ed2k

.if defined(WITHOUT_OPENSSL)
CPPFLAGS+=	-DWITH_RSA
MAKE_ENV+=	LDLIBS="${CPPFLAGS}"
.else
USE_OPENSSL=	yes
OPENSSLSUFFIX=	-openssl
LDLIBS+=	-lmd
MAKE_ENV+=	LDLIBS="${LDLIBS}"
.endif

post-extract:
	${CP} -p ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}/

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ed2k ${PREFIX}/bin/

.include <bsd.port.mk>
