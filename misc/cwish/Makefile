# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	cwish
PORTVERSION=	3.52
PORTREVISION=	2
CATEGORIES=	misc shells
MASTER_SITES=	http://www.predatorlabs.net/dl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses based user friendly windowing shell

NO_WRKSUBDIR=	yes
ALL_TARGET=	cwish
PLIST_FILES=	bin/cwish man/man1/cwish.1.gz
MAKEFILE=	Makefile.FreeBSD

post-patch:
	${REINPLACE_CMD} -e 65d ${WRKSRC}/cwish.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cwish ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cwish.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
