# New ports collection makefile for:    xorg-fonts
# Date created:				Jun 22 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xorg-fonts
PORTVERSION=	7.5.1
CATEGORIES=	x11-fonts
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.org fonts meta-port

USE_XORG=	fontutil

FONTSDIR=	${PREFIX}/lib/X11/fonts
RUN_DEPENDS=	${FONTSDIR}/100dpi/courB08-ISO8859-1.pcf.gz:${PORTSDIR}/x11-fonts/xorg-fonts-100dpi \
		${FONTSDIR}/75dpi/courB08-ISO8859-1.pcf.gz:${PORTSDIR}/x11-fonts/xorg-fonts-75dpi \
		${FONTSDIR}/cyrillic/koi12x24.pcf.gz:${PORTSDIR}/x11-fonts/xorg-fonts-cyrillic \
		${FONTSDIR}/misc/10x20-ISO8859-1.pcf.gz:${PORTSDIR}/x11-fonts/xorg-fonts-miscbitmaps \
		${FONTSDIR}/TTF/luximb.ttf:${PORTSDIR}/x11-fonts/xorg-fonts-truetype \
		${FONTSDIR}/Type1/cour.afm:${PORTSDIR}/x11-fonts/xorg-fonts-type1 \
		${FONTSDIR}/misc/fonts.alias:${PORTSDIR}/x11-fonts/font-alias

NO_BUILD=	yes

do-install:
		${MKDIR} ${PREFIX}/libdata/xorg
		${TOUCH} ${PREFIX}/libdata/xorg/fonts

.include <bsd.port.mk>
