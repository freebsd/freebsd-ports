# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	audacious-skins
PORTVERSION=	0.4
CATEGORIES=	x11-themes
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Collection of audacious skins

BUILD_DEPENDS=	audacious:${PORTSDIR}/multimedia/audacious

USE_XZ=		yes
NO_BUILD=	yes

DATADIR=	${PREFIX}/share/audacious

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/Skins
	${INSTALL_DATA} ${WRKSRC}/Skins/*/*.wsz ${STAGEDIR}${DATADIR}/Skins

.include <bsd.port.mk>
