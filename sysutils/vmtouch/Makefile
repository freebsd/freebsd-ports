# Created by: Mikolaj Golub <trociny@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vmtouch
PORTVERSION=	0.8.0
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	sysutils

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Virtual Memory Toucher

USE_GITHUB=	yes
GH_ACCOUNT=	hoytech

PLIST_FILES=	bin/vmtouch \
		man/man8/vmtouch.8.gz

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/vmtouch ${WRKSRC}/vmtouch.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vmtouch ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/vmtouch.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>
