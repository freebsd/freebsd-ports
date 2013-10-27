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

NO_WRKSUBDIR=	yes
MAKEFILE=	/dev/null
ALL_TARGET=	ed2k
PLIST_FILES=	bin/ed2k

OPTIONS_DEFINE=	OPENSSL
OPTIONS_DEFAULT=OPENSSL
OPENSSL_DESC=	use faster hash libs from OpenSSL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
OPENSSLSUFFIX=	-openssl
USE_OPENSSL=	yes
LDLIBS+=	-lmd
.else
OPENSSLSUFFIX=	-rsa
CFLAGS+=	-DWITH_RSA
.endif

MAKE_ARGS+=	CFLAGS="${CFLAGS}"
MAKE_ENV+=	LDLIBS="${LDLIBS}"

post-extract:
	${CP} -p ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ed2k ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
