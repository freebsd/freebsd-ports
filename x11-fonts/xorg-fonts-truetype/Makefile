# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xorg-fonts-truetype
PORTVERSION=	7.7
CATEGORIES=	x11-fonts
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org TrueType fonts

RUN_DEPENDS=	${FONTDIR}/TTF/luximb.ttf:${PORTSDIR}/x11-fonts/font-bh-ttf \
		${FONTDIR}/OTF/SyrCOMAdiabene.otf:${PORTSDIR}/x11-fonts/font-misc-meltho \
		${FONTDIR}/TTF/GohaTibebZemen.ttf:${PORTSDIR}/x11-fonts/font-misc-ethiopic \
		${LOCALBASE}/lib/X11/fonts/encodings/encodings.dir:${PORTSDIR}/x11-fonts/encodings \
		${LOCALBASE}/lib/X11/fonts/dejavu/DejaVuSans.ttf:${PORTSDIR}/x11-fonts/dejavu

do-install:	# empty

NO_BUILD=	# none
FONTDIR=	${LOCALBASE}/lib/X11/fonts

.include <bsd.port.mk>
