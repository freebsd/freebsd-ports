# Created by: chinsan
# $FreeBSD$

PORTNAME=	vietunicode-web1
PORTVERSION=	2004.04.30
PORTREVISION=	6
CATEGORIES=	vietnamese x11-fonts
MASTER_SITES=	SF/vietunicode/VietFonts-Web1/Web1%20Package%20v2004
DISTNAME=	VietFontsWeb1_ttf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	100% Viet Unicode & Viet Phan/Pali-Sanskrit compatible

USES=		zip
DIST_SUBDIR=	VietUnicode
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

TTF=		vuTimes.ttf vuTimesBold.ttf vuTimesBoldItalic.ttf vuTimesItalic.ttf \
		vuArial.ttf vuArialBold.ttf vuArialBoldItalic.ttf vuArialItalic.ttf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${TTF} ${STAGEDIR}${FONTSDIR})

.include "${.CURDIR}/../../chinese/ttfm/Makefile.ttf"
.include <bsd.port.mk>
