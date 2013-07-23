# Created by: Oleg Ginzburg <olevole@olevole.ru>
# $FreeBSD$

PORTNAME=	ioping
PORTVERSION=	0.7
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	olevole@olevole.ru
COMMENT=	Simple disk I/0 latency measuring tool

LICENSE=	GPLv3

MAN1=		ioping.1
PLIST_FILES=	bin/ioping

MAKE_ENV=	VERSION=${PORTVERSION}

# for the benefit of <80000
CFLAGS+=	-lm

do-build:
	cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} -DVERSION=${PORTVERSION} ioping.c -o ioping

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ioping ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ioping.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
