# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xorg-fonts-100dpi
PORTVERSION=	7.7
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org 100dpi bitmap fonts

RUN_DEPENDS=	${FONTDIR}/100dpi/courB08.pcf.gz:x11-fonts/font-adobe-100dpi \
		${FONTDIR}/100dpi/UTBI__10.pcf.gz:x11-fonts/font-adobe-utopia-100dpi \
		${FONTDIR}/100dpi/luBIS08.pcf.gz:x11-fonts/font-bh-100dpi \
		${FONTDIR}/100dpi/lutBS08.pcf.gz:x11-fonts/font-bh-lucidatypewriter-100dpi \
		${FONTDIR}/100dpi/charB08.pcf.gz:x11-fonts/font-bitstream-100dpi \
		${FONTDIR}/encodings/encodings.dir:x11-fonts/encodings

USES=		metaport

FONTDIR=	${LOCALBASE}/share/fonts

.include <bsd.port.mk>
