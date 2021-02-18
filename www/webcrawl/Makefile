# Created by: Dima Sivachenko
# $FreeBSD$

PORTNAME=	webcrawl
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SUNSITE/apps/www/mirroring

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Download web sites without user interaction by following links

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: pszServerRoot
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: pszServerRoot

USES=		tar:tgz
ALL_TARGET=

PLIST_FILES=	bin/webcrawl man/man1/webcrawl.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/webcrawl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/webcrawl.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
