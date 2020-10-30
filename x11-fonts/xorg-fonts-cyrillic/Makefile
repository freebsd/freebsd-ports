# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xorg-fonts-cyrillic
PORTVERSION=	7.7
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org Cyrillic bitmap fonts

RUN_DEPENDS=	${FONTDIR}/cyrillic/crox1c.pcf.gz:x11-fonts/font-cronyx-cyrillic \
		${FONTDIR}/cyrillic/koi12x24.pcf.gz:x11-fonts/font-misc-cyrillic \
		${FONTDIR}/cyrillic/screen8x16.pcf.gz:x11-fonts/font-screen-cyrillic \
		${FONTDIR}/cyrillic/proof9x16.pcf.gz:x11-fonts/font-winitzki-cyrillic \
		${FONTDIR}/encodings/encodings.dir:x11-fonts/encodings

USES=		metaport

FONTDIR=	${LOCALBASE}/share/fonts

.include <bsd.port.mk>
