# New ports collection makefile for:	bitmap-font
# Version required:	7.18
# Date created:		23 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $Id$
#

DISTNAME=	bitmap-mule-${BITMAP_VER}
PKGNAME=	bitmap-font-${BITMAP_VER}
CATEGORIES=	x11-fonts elisp
MASTER_SITES=	ftp://ftp.jaist.ac.jp/pub/GNU/elisp/bitmap-mule/

MAINTAINER=	shige@FreeBSD.org

# distfile version
BITMAP_VER=	7.18
BITMAP_FONT=	etl8x16-bitmap
FONTSDIR=	lib/X11/fonts/local

USE_X_PREFIX=	yes

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11/XFree86

PLIST_SUB=	FONTSDIR=${FONTSDIR} BITMAP_FONT=${BITMAP_FONT}

do-build:
	@(cd ${WRKSRC}; \
	  bdftopcf ${BITMAP_FONT}.bdf > ${BITMAP_FONT}.pcf ; \
	  ${GZIP_CMD} ${BITMAP_FONT}.pcf ; \
	)

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/REQ ${PKGNAME} INSTALL

do-install:
	@(cd ${WRKSRC}; \
	  ${INSTALL_DATA} ${BITMAP_FONT}.pcf.gz ${PREFIX}/${FONTSDIR} ; \
	)

.include <bsd.port.mk>
