# New ports collection makefile for:	bitmap-fonts
# Date created:		23 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bitmap-fonts
PORTVERSION=	${BITMAP_FONTS_VER}${BITMAP_FONTS_PREVER:S/pre/.p1/}
CATEGORIES=	x11-fonts elisp
MASTER_SITES=	ftp://ftp.jpl.org/pub/elisp/bitmap/ \
		ftp://ftp.jpl.org/pub/elisp/bitmap/snapshots/
DISTNAME=	${PORTNAME}-${BITMAP_FONTS_VER}${BITMAP_FONTS_PREVER}

MAINTAINER=	shige@FreeBSD.org

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11/XFree86

# distfile version
BITMAP_FONTS_VER=	1.0
BITMAP_FONTS_PREVER=	pre
BITMAP_FONTS=		etl6x12-bitmap etl7x14-bitmap etl8x16-bitmap \
			etl10x20-bitmap etl12x24-bitmap
FONTSDIR=		lib/X11/fonts/local
PKGINSTALL=     	${WRKDIR}/INSTALL
PKGDEINSTALL=   	${WRKDIR}/DEINSTALL
WRKSRC=			${WRKDIR}

USE_X_PREFIX=	yes

PLIST_SUB=	FONTSDIR=${FONTSDIR}

do-build:
	@(cd ${WRKSRC}; \
	    for i in ${BITMAP_FONTS} ; do \
	        bdftopcf $${i}.bdf > $${i}.pcf ; \
	        ${GZIP_CMD} $${i}.pcf ; \
	    done ; \
	)
	@for file in INSTALL DEINSTALL; do \
		${SED} -e 's,%%FONTSDIR%%,${FONTSDIR},g' \
			< ${FILESDIR}/$${file}.tmpl > ${WRKDIR}/$${file}; \
	done

pre-install:
	@${SETENV} PKG_PREFIX=${X11BASE} \
		${SH} ${PKGDIR}/REQ ${PKGNAME} INSTALL

do-install:
	@(cd ${WRKSRC}; \
	    for i in ${BITMAP_FONTS} ; do \
	        ${INSTALL_DATA} $${i}.pcf.gz ${X11BASE}/${FONTSDIR} ; \
	    done ; \
	)

post-install:
	@${SETENV} PKG_PREFIX=${X11BASE} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
