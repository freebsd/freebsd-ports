# Created by: Oleg Ginzburg <olevole@olevole.ru>
# $FreeBSD$

PORTNAME=	ioping
PORTVERSION=	0.8
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	olevole@olevole.ru
COMMENT=	Simple disk I/0 latency measuring tool

LICENSE=	GPLv3

PLIST_FILES=	bin/ioping man/man1/ioping.1.gz

MAKE_ENV=	VERSION=${PORTVERSION}

do-build:
	cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} -DVERSION=${PORTVERSION} ioping.c -o ioping

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ioping ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ioping.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
