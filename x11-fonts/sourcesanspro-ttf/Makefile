# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	sourcesanspro-ttf
PORTVERSION=	1.050
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/sourcesans.adobe
DISTNAME=	SourceSansPro_FontsOnly-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Set of fonts by Adobe designed for user interfaces

LICENSE=	OFL11

BUILD_DEPENDS=	mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

NO_BUILD=	yes
USES=		zip
USE_XORG=	x11

PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_SUB=	FONTDIR=${FONTDIR}
SUB_FILES=	pkg-message
SUB_LIST=	FONTDIR=${FONTDIR}

FONTDIR=	lib/X11/fonts/SourceSansPro

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${FONTDIR}
	cd ${WRKSRC}/ && ${INSTALL_DATA} TTF/*.ttf ${STAGEDIR}${PREFIX}/${FONTDIR}

.include <bsd.port.mk>
