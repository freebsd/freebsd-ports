# New ports collection makefile for:    arena
# Version required:     i18n beta-3b
# Date created:         Dec 1 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.14 1999/01/23 07:05:20 vanilla Exp $
#

DISTNAME=       arena-CJK-beta3a
PKGNAME=        arena-i18n-beta3b
CATEGORIES=     www
MASTER_SITES=   ftp://ftp-eu.w3.org/pub/Arena/beta-3/

MAINTAINER=     ache@FreeBSD.ORG

LIB_DEPENDS+=   jpeg.9:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=   png.3:${PORTSDIR}/graphics/png

BROKEN=		png upgrade

USE_XLIB=	yes
WRKSRC=         ${WRKDIR}/WWW

do-build:
	cd ${WRKSRC}/Library/freebsd; ${MAKE}
	cd ${WRKSRC}/Arena/freebsd; \
	${MAKE} PREFIX=${PREFIX} LFLAGS=-L${PREFIX}/lib \
		XLIBDIR=${X11BASE}/lib \
		JPEGDIR=${WRKSRC} PNGDIR=${WRKSRC} ZLIBDIR=${WRKSRC} \
		JPEGLIB=-ljpeg PNGLIB=-lpng ZLIB=-lz

do-install:
	cd ${WRKSRC}/Arena/freebsd; \
	${INSTALL} -c -m ${BINMODE} -o ${BINOWN} -g ${BINGRP} -s arena ${PREFIX}/bin

.include <bsd.port.mk>
