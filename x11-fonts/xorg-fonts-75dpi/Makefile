# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xorg-fonts-75dpi
PORTVERSION=	7.7
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org 75dpi bitmap fonts

RUN_DEPENDS=	${FONTDIR}/75dpi/courB08.pcf.gz:x11-fonts/font-adobe-75dpi \
		${FONTDIR}/75dpi/UTBI__10.pcf.gz:x11-fonts/font-adobe-utopia-75dpi \
		${FONTDIR}/75dpi/luBIS08.pcf.gz:x11-fonts/font-bh-75dpi \
		${FONTDIR}/75dpi/lutBS08.pcf.gz:x11-fonts/font-bh-lucidatypewriter-75dpi \
		${FONTDIR}/75dpi/charB08.pcf.gz:x11-fonts/font-bitstream-75dpi \
		${FONTDIR}/encodings/encodings.dir:x11-fonts/encodings

USES=		metaport

FONTDIR=	${LOCALBASE}/share/fonts

.include <bsd.port.mk>
