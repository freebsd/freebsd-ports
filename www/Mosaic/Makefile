# New ports collection makefile for:    Mosaic browser
# Version required:     2.7b5
# Date created:         7 August 1995
# Whom:                 torstenb
#
# $Id: Makefile,v 1.11 1996/11/18 01:26:28 ache Exp $
#

DISTNAME=       Mosaic-src-2.7b5
PKGNAME=        mosaic-2.7b5
CATEGORIES=     www
MASTER_SITES=	ftp://ftp.ncsa.uiuc.edu/Web/Mosaic/Unix/source/

LIB_DEPENDS=    jpeg\\.7\\.:${PORTSDIR}/graphics/jpeg \
		png\\.0\\.:${PORTSDIR}/graphics/png \
		Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \

REQUIRES_MOTIF=	yes
WRKSRC=		${WRKDIR}/Mosaic-src
ALL_TARGET=	bsdi
USE_X11=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/Mosaic ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/app-defaults.color ${PREFIX}/lib/X11/app-defaults/Mosaic

.include <bsd.port.mk>
