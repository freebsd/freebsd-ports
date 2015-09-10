# Created by: Chie Taguchi <taguchi.ch@gmail.com>
# $FreeBSD$

PORTNAME=	masscan
PORTVERSION=	1.0.3
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

pre-build:
	@${REINPLACE_CMD} -e "s|SYS :=|SYS ?=|"\
	-e "s|describe --tags|describe --tags 2> /dev/null|" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/masscan ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/masscan.8 ${STAGEDIR}${MANPREFIX}/man/man8

regression-test: build
	${WRKSRC}/bin/masscan --selftest

.include <bsd.port.mk>
