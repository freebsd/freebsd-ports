# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xorg-fonts-type1
PORTVERSION=	7.7
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org Type1 fonts

RUN_DEPENDS=	${FONTDIR}/Type1/UTBI____.afm:x11-fonts/font-adobe-utopia-type1 \
		${FONTDIR}/Type1/l047013t.afm:x11-fonts/font-bh-type1 \
		${FONTDIR}/Type1/c0419bt_.afm:x11-fonts/font-bitstream-type1 \
		${FONTDIR}/Type1/cour.afm:x11-fonts/font-ibm-type1 \
		${FONTDIR}/Type1/cursor.pfa:x11-fonts/font-xfree86-type1 \
		${FONTDIR}/encodings/encodings.dir:x11-fonts/encodings

USES=		metaport

FONTDIR=	${LOCALBASE}/share/fonts

.include <bsd.port.mk>
