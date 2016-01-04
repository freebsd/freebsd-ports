# Created by: Nikolai Lifanov <lifanov@mail.lifanov.com>
# $FreeBSD$

PORTNAME=	hashcat
PORTVERSION=	2.00
CATEGORIES=	security

MAINTAINER=	lifanov@mail.lifanov.com
COMMENT=	Advanced CPU-based password recovery utility

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/license.txt

BROKEN_FreeBSD_9=	does not build

USE_GITHUB=	yes
GH_ACCOUNT=	hashcat

USE_GCC=	any

USES=		gmake

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	uses amd64 instructions

ALL_TARGET=	posix64 posixXOP

do-install:
.for v in 64 XOP
	${INSTALL_PROGRAM} ${WRKSRC}/hashcat-cli${v}.bin ${STAGEDIR}${LOCALBASE}/bin
.endfor
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "charsets rules tables salts" ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
