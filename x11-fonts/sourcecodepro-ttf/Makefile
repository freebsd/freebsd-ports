# Created by: Masaki TAGAWA <masaki@club.kyutech.ac.jp>
# $FreeBSD$

PORTNAME=	sourcecodepro-ttf
PORTVERSION=	1.017
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/sourcecodepro.adobe
DISTNAME=	SourceCodePro_FontsOnly-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Set of fonts by Adobe designed for coders

LICENSE=	OFL11

BUILD_DEPENDS=	${LOCALBASE}/bin/fc-cache:${PORTSDIR}/x11-fonts/fontconfig \
		${LOCALBASE}/bin/mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		${LOCALBASE}/bin/mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

NO_BUILD=	yes
USE_XORG=	x11
USES=		zip

PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"
SUB_FILES=	pkg-message
SUB_LIST=	FONTDIR=${FONTDIR}

FONTDIR=	${PREFIX}/lib/X11/fonts/SourceCodePro

do-install:
	${MKDIR} ${STAGEDIR}${FONTDIR}/
	cd ${WRKSRC}/TTF/ && ${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTDIR}/

.include <bsd.port.mk>
