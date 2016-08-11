# Created by: Oleg Ginzburg <olevole@olevole.ru>
# $FreeBSD$

PORTNAME=	ioping
PORTVERSION=	0.9
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	olevole@olevole.ru
COMMENT=	Simple disk I/0 latency measuring tool

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	koct9i

PLIST_FILES=	bin/ioping man/man1/ioping.1.gz

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -DVERSION=${PORTVERSION} ioping.c \
		-o ioping ${LDFLAGS} -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ioping ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ioping.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
