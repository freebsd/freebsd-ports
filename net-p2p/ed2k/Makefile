# $FreeBSD$

PORTNAME=	ed2k
PORTVERSION=	1.4
CATEGORIES=	net-p2p
MASTER_SITES=	http://www.sdalu.com/download/software/tools/
PKGNAMESUFFIX=	-hash${OPENSSLSUFFIX}${PKGNAMESUFFIX2}
DISTNAME=	ed2k.c
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Calculates 'eMule' hashes or producing ed2k:// file links

CONFLICTS=	amule-*
NO_STAGE=	yes

NO_WRKSUBDIR=	yes
MAKEFILE=	/dev/null
ALL_TARGET=	ed2k
PLIST_FILES=	bin/ed2k

.if defined(WITHOUT_OPENSSL)
OPENSSLSUFFIX=	-rsa
CFLAGS+=	-DWITH_RSA
.else
OPENSSLSUFFIX=	-openssl
USE_OPENSSL=	yes
LDLIBS+=	-lmd
.endif

MAKE_ARGS+=	CFLAGS="${CFLAGS}"
MAKE_ENV+=	LDLIBS="${LDLIBS}"

post-extract:
	${CP} -p ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ed2k ${PREFIX}/bin/

.include <bsd.port.mk>
