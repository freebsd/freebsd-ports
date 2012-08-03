# New ports collection makefile for:	mondulkiri
# Date created:		August 8 2010
# Whom:			Kuan-Chung Chiu <buganini@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mondulkiri
PORTVERSION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/khmer/Fonts%20-%20Mondulkiri/Mondulkiri%20Unicode%20Fonts%20v2E3s/
DISTNAME=	Mondulkiri_Unicode_fonts_V2E3s

MAINTAINER=	buganini@gmail.com
COMMENT=	Mondulkiri Khmer fonts

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_ZIP=	yes
NO_BUILD=	yes

FONTSDIR=	lib/X11/fonts/Khmer/
PLIST_SUB+=	FONTSDIR=${FONTSDIR}

WRKSRC=		${WRKDIR}/Opentype\ only\ fonts

do-install:
	${MKDIR} ${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${PREFIX}/${FONTSDIR}

post-install:
	@${ECHO_MSG} "==> Running fc-cache"
	@-${LOCALBASE}/bin/fc-cache -f -v ${PREFIX}/${FONTSDIR}

.include <bsd.port.mk>
