# Created by: Babak Farrokhi <babak@farrokhi.net>
# $FreeBSD$

PORTNAME=	farsifonts
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/farsi-fonts/

MAINTAINER=	javad.kouhi@gmail.com
COMMENT=	Standard set of Unicode Persian fonts

BUILD_DEPENDS=	ttmkfdir:${PORTSDIR}/x11-fonts/ttmkfdir

USES=		zip
PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"
FONTSDIR?=	${PREFIX}/lib/X11/fonts/${PORTNAME}

do-build:
	@ttmkfdir -c -d ${WRKSRC} -o ${WRKSRC}/fonts.dir

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/fonts/farsifonts
	@${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${PREFIX}/lib/X11/fonts/farsifonts
	@${INSTALL_DATA} ${WRKSRC}/fonts.dir ${STAGEDIR}${PREFIX}/lib/X11/fonts/farsifonts

.include <bsd.port.mk>
