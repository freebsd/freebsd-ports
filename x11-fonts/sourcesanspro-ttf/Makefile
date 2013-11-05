# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	sourcesanspro-ttf
PORTVERSION=	1.050
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/sourcesans.adobe
DISTNAME=	SourceSansPro_FontsOnly-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	A set of fonts by Adobe designed for user interfaces

LICENSE=	OFL11

BUILD_DEPENDS=	mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale	\
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

USE_ZIP=	yes
USE_XORG=	x11

PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_LIST=	FONTDIR=${FONTDIR}

FONTNAME=	SourceSansPro
FONTDIR=	${PREFIX}/lib/X11/fonts/${FONTNAME}
INSTDAT=		fonts.dir fonts.scale

MKFONTSCL_CMD=	${LOCALBASE}/bin/mkfontscale
MKFONTDIR_CMD=	${LOCALBASE}/bin/mkfontdir

do-build:
	cd ${WRKSRC}/ && ${MKFONTSCL_CMD}
	cd ${WRKSRC}/ && ${MKFONTDIR_CMD}

do-install:
	${MKDIR} ${STAGEDIR}${FONTDIR}
	cd ${WRKSRC}/ &&	\
	${INSTALL_DATA} ${INSTDAT} TTF/*.ttf ${STAGEDIR}${FONTDIR}

.include <bsd.port.mk>
