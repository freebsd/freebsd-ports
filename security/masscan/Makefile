# Created by: Chie Taguchi <taguchi.ch@gmail.com>
# $FreeBSD$

PORTNAME=	masscan
PORTVERSION=	1.0.4
CATEGORIES=	security

MAINTAINER=	taguchi.ch@gmail.com
COMMENT=	Very fast port scanner

LICENSE=	GPLv3

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	robertdavidgraham
CFLAGS+=	-Wno-format
MAKE_ARGS=	SYS=freebsd CC="${CC}" CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/masscan man/man8/masscan.8.gz

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64 || ${ARCH} == powerpc
USE_GCC=	any
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/masscan ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/masscan.8 ${STAGEDIR}${MANPREFIX}/man/man8

do-test:
	${WRKSRC}/bin/masscan --selftest

.include <bsd.port.mk>
