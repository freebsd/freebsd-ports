# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	lmclock
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	x11-clocks
MASTER_SITES=	LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Xerox Lisp machine clock clone

USES=		imake xorg
USE_XORG=	x11 xext

PLIST_FILES=	bin/lmclock

post-extract:
	@${TOUCH} ${WRKSRC}/lmclock.man

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
