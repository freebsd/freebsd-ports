# New ports collection makefile for:    arena
# Date created:         Dec 1 1995
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	arena-i18n
PORTVERSION=	beta3b
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.w3.org/pub/Arena/beta-3/
DISTNAME=	arena-CJK-beta3a

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Experimental HTML 3 browser, supports math and style sheets

LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png

PLIST_FILES=	bin/arena
USE_XLIB=	yes
WRKSRC=		${WRKDIR}/WWW

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
