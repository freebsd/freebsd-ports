# Created by: Thomas Hurst <tom@hur.st>
# $FreeBSD$

PORTNAME=	jdupes
DISTVERSIONPREFIX=	v
DISTVERSION=	1.12
CATEGORIES=	sysutils

MAINTAINER=	tom@hur.st
COMMENT=	Powerful duplicate file finder and an enhanced fork of 'fdupes'

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	jbruchon

USES=	gmake

PLIST_FILES=	bin/jdupes man/man1/jdupes.1.gz

OPTIONS_DEFINE=	LOW_MEMORY
LOW_MEMORY_DESC=	Build for lower memory usage instead of speed
LOW_MEMORY_MAKE_ENV=	CFLAGS_EXTRA=-DLOW_MEMORY

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
