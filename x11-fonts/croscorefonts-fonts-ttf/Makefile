# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	croscorefonts
PORTVERSION=	1.23.0
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://gsdview.appspot.com/chromeos-localmirror/distfiles/ \
		LOCAL/sunpoet

MAINTAINER=	office@FreeBSD.org
COMMENT=	Fonts created from by Google for ChromeOS to replace MS TTF

#LICENSE=	OFL
#LICENSE_NAME=	SIL OPEN FONT LICENSE Version 1.1
#LICENSE_FILE=	${WRKSRC}/LICENSE
#LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		fonts
USE_XORG=	x11

PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"
SUB_FILES=	pkg-message

FONTNAME=	ChromeOS
FONTSDIR=	${PREFIX}/lib/X11/fonts/${FONTNAME}
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
