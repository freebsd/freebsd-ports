# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	croscorefonts
PORTVERSION=	1.23.0
CATEGORIES=	x11-fonts
MASTER_SITES=	http://gsdview.appspot.com/chromeos-localmirror/distfiles/ \
		LOCAL/sunpoet

MAINTAINER=	office@FreeBSD.org
COMMENT=	Fonts created from by Google for ChromeOS to replace MS TTF

#LICENSE=	OFL
#LICENSE_NAME=	SIL OPEN FONT LICENSE Version 1.1
#LICENSE_FILE=	${WRKSRC}/LICENSE
#LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

USE_XORG=	x11

PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_LIST=	FONTDIR=${FONTDIR}

FONTNAME=	ChromeOS
FONTDIR=	${PREFIX}/lib/X11/fonts/${FONTNAME}
INSTDAT=	fonts.dir fonts.scale

MKFONTSCL_CMD=	${LOCALBASE}/bin/mkfontscale
MKFONTDIR_CMD=	${LOCALBASE}/bin/mkfontdir

do-build:
	cd ${WRKSRC} && ${MKFONTSCL_CMD}
	${REINPLACE_CMD} -e 's|-misc-|-google-|' ${WRKSRC}/fonts.scale
	cd ${WRKSRC} && ${MKFONTDIR_CMD}

do-install:
	${MKDIR} ${STAGEDIR}${FONTDIR}
	cd ${WRKSRC} &&	\
	${INSTALL_DATA} ${INSTDAT} *.ttf ${STAGEDIR}${FONTDIR}

.include <bsd.port.mk>
