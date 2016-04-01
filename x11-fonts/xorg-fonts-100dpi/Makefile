# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xorg-fonts-100dpi
PORTVERSION=	7.7
CATEGORIES=	x11-fonts
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org 100dpi bitmap fonts

RUN_DEPENDS=	${FONTDIR}/100dpi/courB08.pcf.gz:x11-fonts/font-adobe-100dpi \
		${FONTDIR}/100dpi/UTBI__10.pcf.gz:x11-fonts/font-adobe-utopia-100dpi \
		${FONTDIR}/100dpi/luBIS08.pcf.gz:x11-fonts/font-bh-100dpi \
		${FONTDIR}/100dpi/lutBS08.pcf.gz:x11-fonts/font-bh-lucidatypewriter-100dpi \
		${FONTDIR}/100dpi/charB08.pcf.gz:x11-fonts/font-bitstream-100dpi \
		${FONTDIR}/encodings/encodings.dir:x11-fonts/encodings

CONFLICTS=	XFree86-font100dpi-*

NO_BUILD=	# none
NO_MTREE=	yes
NO_INSTALL=	yes
FONTDIR=	${LOCALBASE}/share/fonts

.include <bsd.port.mk>
