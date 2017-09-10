# Created by: Nikolai Lifanov <lifanov@mail.lifanov.com>
# $FreeBSD$

PORTNAME=	hashcat-legacy
PORTVERSION=	2.00
PORTREVISION=	3
CATEGORIES=	security

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Advanced CPU-based password recovery utility

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/license.txt

LIB_DEPENDS=	libgmp.so:math/gmp

USE_GITHUB=	yes
GH_ACCOUNT=	hashcat

USE_GCC=	any

USES=		gmake

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	uses amd64 instructions

ALL_TARGET=	posix64 posixXOP

post-patch:
	@${REINPLACE_CMD} -r 's|^(CC_.*[[:blank:]]*=[[:blank:]]*)gcc[[:blank:]]*$$|\1${CC}|' ${WRKSRC}/src/Makefile

do-install:
.for v in 64 XOP
	${INSTALL_PROGRAM} ${WRKSRC}/hashcat-cli${v}.bin ${STAGEDIR}${LOCALBASE}/bin
.endfor
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "charsets rules tables salts" ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
