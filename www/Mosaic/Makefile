# New ports collection makefile for:    Mosaic browser
# Version required:     2.7b4
# Date created:         7 August 1995
# Whom:                 torstenb
#
# $Id: Makefile,v 1.7 1996/02/19 21:39:24 ache Exp $
#

DISTNAME=       Mosaic-src-2.7b4
PKGNAME=        mosaic-2.7b4
CATEGORIES+=	www
MASTER_SITES=	ftp://ftp.ncsa.uiuc.edu/Web/Mosaic/Unix/source/

LIB_DEPENDS=	jpeg\\.6\\.:${PORTSDIR}/graphics/jpeg \
		png\\.0\\.:${PORTSDIR}/graphics/png \
		z\\.1\\.:${PORTSDIR}/devel/libz

REQUIRES_MOTIF=	yes
WRKSRC=		${WRKDIR}/Mosaic-src
ALL_TARGET=	bsdi
USE_X11=	yes

# don't waste diskspace
post-extract:
	@rm -rf ${WRKSRC}/libjpeg ${WRKSRC}/libpng

do-install:
	${INSTALL} -c -s -g ${BINGRP} -m ${BINMODE} -o ${BINOWN} ${WRKSRC}/src/Mosaic ${PREFIX}/bin/Mosaic
	${INSTALL} -c -g ${BINGRP} -m ${NOBINMODE} -o ${BINOWN} ${WRKSRC}/app-defaults.color ${PREFIX}/lib/X11/app-defaults/Mosaic

.include <bsd.port.mk>
