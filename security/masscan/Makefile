# Created by: Chie Taguchi <taguchi.ch@gmail.com>
# $FreeBSD$

PORTNAME=	masscan
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	http://github.com/robertdavidgraham/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/

MAINTAINER=	taguchi.ch@gmail.com
COMMENT=	Very fast port scanner

LICENSE=	GPLv3

FETCH_ARGS=	-Fpr
USES=		gmake
CFLAGS+=	-I. -Wno-format
MAKE_ARGS=	SYS=freebsd CC=${CC} CFLAGS="${CFLAGS}" LIBS="-lpcap -lm ${PTHREAD_LIBS}"

PLIST_FILES=	bin/masscan man/man8/masscan.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/masscan ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/masscan.8 ${STAGEDIR}${MANPREFIX}/man/man8

regression-test: build
	${WRKSRC}/bin/masscan --selftest

.include <bsd.port.mk>
