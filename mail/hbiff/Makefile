# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	hbiff
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	ftp://nuxi.ucdavis.edu/pub/misc/  \
		LOCAL/obrien

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Replacement for xbiff that handles popup window with mail headers

USES=		xorg
USE_XORG=	x11

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
LDFLAGS+=	-lX11

PLIST_FILES=	bin/hbiff man/man1/hbiff.1.gz

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} ${WRKSRC}/hbiff.c -o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
