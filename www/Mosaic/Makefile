# New ports collection makefile for:    Mosaic browser
# Version required:     2.7b2
# Date created:         7 August 1995
# Whom:                 torstenb
#
# $Id: Makefile,v 1.6 1995/12/05 05:12:48 ache Exp $
#

DISTNAME=       Mosaic-src-2.7b2
PKGNAME=        mosaic-2.7b2
CATEGORIES=	www
EXTRACT_SUFX=   .tar.Z

MASTER_SITES=	ftp://ftp.ncsa.uiuc.edu/Web/Mosaic/Unix/source/

LIB_DEPENDS+=   jpeg\\.6\\.:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=   png\\.0\\.:${PORTSDIR}/graphics/png
WRKSRC=		${WRKDIR}/Mosaic-src
ALL_TARGET=	default

# don't waste diskspace
post-extract:
	@rm -rf ${WRKSRC}/libjpeg ${WRKSRC}/libpng

.include <bsd.port.mk>
