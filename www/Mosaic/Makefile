# New ports collection makefile for:    Mosaic browser
# Date created:         7 August 1995
# Whom:                 torstenb
#
# $FreeBSD$
#

PORTNAME=	mosaic
PORTVERSION= 	2.7b5
CATEGORIES=     www
MASTER_SITES=	ftp://ftp.ncsa.uiuc.edu/Web/Mosaic/Unix/source/
DISTNAME=	Mosaic-src-2.7b5

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.4:${PORTSDIR}/graphics/png \
		Xpm.4:${PORTSDIR}/graphics/xpm \

REQUIRES_MOTIF=	yes
WRKSRC=		${WRKDIR}/Mosaic-src
ALL_TARGET=	bsdi
USE_X_PREFIX=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/Mosaic ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/app-defaults.color ${PREFIX}/lib/X11/app-defaults/Mosaic

.include <bsd.port.mk>
