# New ports collection makefile for:    Mosaic
# Version required:     2.6
# Date created:         7 August 1995
# Whom:                 torstenb
#
# $Id$
#

DISTNAME=	Mosaic-src-2.6
CATEGORIES=	networking
LIB_DEPENDS=	jpeg\\.5\\.:${PORTSDIR}/graphics/jpeg
WRKSRC=		${WRKDIR}/Mosaic-src
ALL_TARGET=	default

# don't waste diskspace
post-extract:
	@rm -rf ${WRKSRC}/libjpeg

.include <bsd.port.mk>
