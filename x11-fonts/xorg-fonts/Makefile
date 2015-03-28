# $FreeBSD$

PORTNAME=	xorg-fonts
PORTVERSION=	7.7
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.org fonts meta-port

USE_XORG=	fontutil

RUN_DEPENDS=	xorg-fonts-100dpi>0:${PORTSDIR}/x11-fonts/xorg-fonts-100dpi \
		xorg-fonts-75dpi>0:${PORTSDIR}/x11-fonts/xorg-fonts-75dpi \
		xorg-fonts-cyrillic>0:${PORTSDIR}/x11-fonts/xorg-fonts-cyrillic \
		xorg-fonts-miscbitmaps>0:${PORTSDIR}/x11-fonts/xorg-fonts-miscbitmaps \
		xorg-fonts-truetype>0:${PORTSDIR}/x11-fonts/xorg-fonts-truetype \
		xorg-fonts-type1>0:${PORTSDIR}/x11-fonts/xorg-fonts-type1 \
		font-alias>0:${PORTSDIR}/x11-fonts/font-alias

NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes

.include <bsd.port.mk>
