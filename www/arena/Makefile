# New ports collection makefile for:    arena
# Version required:     beta-2b
# Date created:         Dec 1 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.3 1996/02/20 05:33:45 asami Exp $
#

DISTNAME=       arena-beta-2b
PKGNAME=        arena-b2b
CATEGORIES+=    www
MASTER_SITES=   ftp://ftp.w3.org/pub/arena/beta-2/
EXTRACT_SUFX=   -src.tar.gz

MAINTAINER=     ache@FreeBSD.ORG

LIB_DEPENDS+=   jpeg\\.6\\.:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=   png\\.0\\.:${PORTSDIR}/graphics/png

WRKSRC=         ${WRKDIR}/WWW

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
