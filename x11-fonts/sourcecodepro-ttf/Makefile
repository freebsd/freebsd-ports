# Created by: Masaki TAGAWA <masaki@club.kyutech.ac.jp>
# $FreeBSD$

PORTNAME=	sourcecodepro-ttf
PORTVERSION=	1.017
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/sourcecodepro.adobe
DISTNAME=	SourceCodePro_FontsOnly-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of fonts by Adobe designed for coders

LICENSE=	OFL11

BUILD_DEPENDS=	mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale	\
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USES=		zip
USE_XORG=	x11

PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_LIST=	FONTDIR=${FONTDIR}

FONTNAME=	SourceCodePro
FONTDIR=	${PREFIX}/lib/X11/fonts/${FONTNAME}
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTDIR}
	cd ${WRKSRC}/TTF/ &&	\
	${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTDIR}

.include <bsd.port.mk>
