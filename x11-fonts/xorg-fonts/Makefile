# $FreeBSD$

PORTNAME=	xorg-fonts
PORTVERSION=	7.7
CATEGORIES=	x11-fonts
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.org fonts meta-port

USE_XORG=	fontutil

FONTSDIR=	${PREFIX}/lib/X11/fonts
RUN_DEPENDS=	xorg-fonts-100dpi>=0:${PORTSDIR}/x11-fonts/xorg-fonts-100dpi \
		xorg-fonts-75dpi>=0:${PORTSDIR}/x11-fonts/xorg-fonts-75dpi \
		xorg-fonts-cyrillic>=0:${PORTSDIR}/x11-fonts/xorg-fonts-cyrillic \
		xorg-fonts-miscbitmaps>=0:${PORTSDIR}/x11-fonts/xorg-fonts-miscbitmaps \
		xorg-fonts-truetype>=0:${PORTSDIR}/x11-fonts/xorg-fonts-truetype \
		xorg-fonts-type1>=0:${PORTSDIR}/x11-fonts/xorg-fonts-type1 \
		${FONTSDIR}/misc/fonts.alias:${PORTSDIR}/x11-fonts/font-alias

NO_BUILD=	yes

do-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/libdata/xorg
		${TOUCH} ${STAGEDIR}${PREFIX}/libdata/xorg/fonts

.include <bsd.port.mk>
