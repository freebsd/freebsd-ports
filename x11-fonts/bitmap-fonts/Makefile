# New ports collection makefile for:	bitmap-font
# Version required:	8.0
# Date created:		23 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	bitmap-mule-${BITMAP_VER}
PKGNAME=	bitmap-font-${BITMAP_VER}
CATEGORIES=	x11-fonts elisp
MASTER_SITES=	ftp://ftp.jpl.org/pub/elisp/bitmap/

MAINTAINER=	shige@FreeBSD.org

# distfile version
BITMAP_VER=	8.0
BITMAP_FONT=	etl8x16-bitmap
FONTSDIR=	lib/X11/fonts/local
PKGINSTALL=     ${WRKDIR}/INSTALL
PKGDEINSTALL=   ${WRKDIR}/DEINSTALL

USE_X_PREFIX=	yes

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11/XFree86

PLIST_SUB=	FONTSDIR=${FONTSDIR} BITMAP_FONT=${BITMAP_FONT}

do-build:
	@(cd ${WRKSRC}; \
	  bdftopcf ${BITMAP_FONT}.bdf > ${BITMAP_FONT}.pcf ; \
	  ${GZIP_CMD} ${BITMAP_FONT}.pcf ; \
	)
	@for file in INSTALL DEINSTALL; do \
		${SED} -e 's,%%FONTSDIR%%,${FONTSDIR},g' \
			< ${FILESDIR}/$${file}.tmpl > ${WRKDIR}/$${file}; \
	done


pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/REQ ${PKGNAME} INSTALL

do-install:
	@(cd ${WRKSRC}; \
	  ${INSTALL_DATA} ${BITMAP_FONT}.pcf.gz ${PREFIX}/${FONTSDIR} ; \
	)

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
