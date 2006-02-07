# New ports collection makefile for:	farsifonts
# Date created:				06 FEB 2006
# Whom:					Babak Farrokhi <babak@farrokhi.net>
#
# $FreeBSD$
#

PORTNAME=	farsifonts
PORTVERSION=	0.4
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.farsiweb.info/font/

MAINTAINER=	babak@farrokhi.net
COMMENT=	Standard set of Unicode Persian fonts

BUILD_DEPENDS=	ttmkfdir:${PORTSDIR}/x11-fonts/ttmkfdir

USE_X_PREFIX=	yes
USE_ZIP=	yes

do-build:
	@ttmkfdir -c -d ${WRKSRC} > ${WRKSRC}/fonts.dir

do-install:
	@${MKDIR} ${PREFIX}/lib/X11/fonts/farsifonts
	@${INSTALL_DATA} ${WRKSRC}/*.ttf ${PREFIX}/lib/X11/fonts/farsifonts
	@${INSTALL_DATA} ${WRKSRC}/*.dir ${PREFIX}/lib/X11/fonts/farsifonts

.include <bsd.port.mk>
