# New ports collection makefile for:    arena
# Version required:     beta-1e
# Date created:         Dec 1 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.1.1.1 1995/12/01 22:05:30 ache Exp $
#

DISTNAME=       arena-beta-1e
CATEGORIES+=    www x11
MASTER_SITES=   ftp://ftp.w3.org/pub/arena/beta-1/
DISTFILES=      arena-beta-1e-src.tgz
WRKSRC=         ${WRKDIR}/WWW
LIB_DEPENDS+=   jpeg\\.6\\.:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=   png\\.0\\.:${PORTSDIR}/graphics/png

MAINTAINER=     ache@FreeBSD.ORG

do-build:
	cd ${WRKSRC}/Library/freebsd; ${MAKE}
	cd ${WRKSRC}; ln -fs ${PREFIX}/include Implementation
	cd ${WRKSRC}/Arena/freebsd; \
	${MAKE} LFLAGS=-L${PREFIX}/lib \
		JPEGDIR=${WRKSRC} PNGDIR=${WRKSRC} ZLIBDIR=${WRKSRC} \
		JPEGLIB=-ljpeg PNGLIB=-lpng ZLIB=-lz

do-install:
	cd ${WRKSRC}/Arena/freebsd; \
	${INSTALL} -c -m ${BINMODE} -o ${BINOWN} -g ${BINGRP} -s arena ${PREFIX}/bin

.include <bsd.port.mk>
