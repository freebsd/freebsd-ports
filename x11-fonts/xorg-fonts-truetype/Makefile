# New ports collection makefile for:    xorg-fonts-truetype
# Date created:		30 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xorg-fonts-truetype
PORTVERSION=	7.3
CATEGORIES=	x11-fonts
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org TrueType fonts

RUN_DEPENDS=	${FONTDIR}/TTF/luximb.ttf:${PORTSDIR}/x11-fonts/font-bh-ttf \
		${FONTDIR}/OTF/SyrCOMAdiabene.otf:${PORTSDIR}/x11-fonts/font-misc-meltho \
		${FONTDIR}/TTF/GohaTibebZemen.ttf:${PORTSDIR}/x11-fonts/font-misc-ethiopic \
		${X11BASE}/lib/X11/fonts/encodings/encodings.dir:${PORTSDIR}/x11-fonts/encodings \
		${X11BASE}/lib/X11/fonts/bitstream-vera/VeraIt.ttf:${PORTSDIR}/x11-fonts/bitstream-vera \

CONFLICTS=	XFree86-fontScalable-*

do-install:	# empty

NO_BUILD=	# none
FONTDIR=	${X11BASE}/lib/X11/fonts

.include <bsd.port.mk>
