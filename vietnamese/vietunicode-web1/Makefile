# New ports collection makefile for:	vietunicode-web1
# Date created:		2007/01/06
# Whom:			chinsan
#
# $FreeBSD$
#

PORTNAME=	vietunicode-web1
PORTVERSION=	2004.04.30
PORTREVISION=	1
CATEGORIES=	vietnamese x11-fonts
MASTER_SITES=	SF/vietunicode/VietFonts-Web1/Web1%20Package%20v2004
DISTNAME=	VietFontsWeb1_ttf

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	100% Viet Unicode & Viet Phan/Pali-Sanskrit compatible

USE_ZIP=	yes
DIST_SUBDIR=	VietUnicode
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

TTF=		vuTimes.ttf vuTimesBold.ttf vuTimesBoldItalic.ttf vuTimesItalic.ttf \
		vuArial.ttf vuArialBold.ttf vuArialBoldItalic.ttf vuArialItalic.ttf

do-install:
	@${MKDIR} ${FONTSDIR}
.for i in ${TTF}
	${INSTALL_DATA} ${WRKSRC}/${i} ${FONTSDIR}
.endfor

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/chinese/ttfm/Makefile.ttf"
.include <bsd.port.post.mk>
