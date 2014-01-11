# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	wmblueclock
PORTVERSION=	0.0
PORTREVISION=	2
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/xutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple dockable clock application

USE_BZIP2=	yes
USE_XORG=	x11 xau xdmcp xext xpm

PLIST_FILES=	bin/wmblueclock man/man1/${PORTNAME}.1.gz

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
