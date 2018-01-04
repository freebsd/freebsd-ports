# Created by: Chie Taguchi <taguchi.ch@gmail.com>
# $FreeBSD$

PORTNAME=	masscan
PORTVERSION=	1.0.4
CATEGORIES=	security

MAINTAINER=	taguchi.ch@gmail.com
COMMENT=	Very fast port scanner

LICENSE=	GPLv3

BROKEN_aarch64=		invokes x86 assembler
BROKEN_armv6=		invokes x86 assembler
BROKEN_armv7=		invokes x86 assembler
BROKEN_mips=		invokes x86 assembler
BROKEN_mips64=		invokes x86 assembler
BROKEN_sparc64=		invokes x86 assembler
BROKEN_powerpc64=	invokes x86 assembler

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
