# Created by: Chie Taguchi <taguchi.ch@gmail.com>
# $FreeBSD$

PORTNAME=	masscan
PORTVERSION=	1.0.4
CATEGORIES=	security

MAINTAINER=	taguchi.ch@gmail.com
COMMENT=	Very fast port scanner

LICENSE=	GPLv3

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	uses i386 assembler

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	robertdavidgraham
CFLAGS+=	-Wno-format
MAKE_ARGS=	SYS=freebsd CC="${CC}" CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/masscan man/man8/masscan.8.gz

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1100000
BUILD_DEPENDS+=	clang38:lang/clang38
CC=	clang38
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/masscan ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/masscan.8 ${STAGEDIR}${MANPREFIX}/man/man8

regression-test: build
	${WRKSRC}/bin/masscan --selftest

.include <bsd.port.post.mk>
