# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xorg-fonts-truetype
PORTVERSION=	7.7
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org TrueType fonts

RUN_DEPENDS=	${FONTDIR}/TTF/luximb.ttf:x11-fonts/font-bh-ttf \
		${FONTDIR}/OTF/SyrCOMAdiabene.otf:x11-fonts/font-misc-meltho \
		${FONTDIR}/TTF/GohaTibebZemen.ttf:x11-fonts/font-misc-ethiopic \
		${FONTDIR}/encodings/encodings.dir:x11-fonts/encodings \
		${FONTDIR}/dejavu/DejaVuSans.ttf:x11-fonts/dejavu

NO_BUILD=	# none
NO_INSTALL=	yes
NO_MTREE=	yes
FONTDIR=	${LOCALBASE}/share/fonts

.include <bsd.port.mk>
