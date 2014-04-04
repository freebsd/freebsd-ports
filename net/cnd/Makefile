# Created by: Daniel Bryan <sisko@bsdmail.com>
# $FreeBSD$

PORTNAME=	cnd
PORTVERSION=	0.7
CATEGORIES=	net
MASTER_SITES=	http://www.bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Console network display

PLIST_FILES=	bin/cnd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
