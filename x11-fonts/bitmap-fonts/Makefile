# New ports collection makefile for:	bitmap-fonts
# Date created:		23 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bitmap-fonts
PORTVERSION=	${BITMAP_FONTS_VER}
CATEGORIES=	x11-fonts elisp
MASTER_SITES=	ftp://ftp.jpl.org/pub/elisp/bitmap/ \
		ftp://ftp.jpl.org/pub/elisp/bitmap/snapshots/
DISTNAME=	${PORTNAME}-${BITMAP_FONTS_VER}

MAINTAINER=	shige@FreeBSD.org
COMMENT=	Bitmap font, (6x12, 7x14, 8x16, 12x24) dots bitmap font

BUILD_DEPENDS=	bdftopcf:${X_CLIENTS_PORT}

# distfile version
BITMAP_FONTS_VER=	1.0
BITMAP_FONTS_SIZE=	12 14 16 20 24
FONTSDIR=	lib/X11/fonts/local
PKGINSTALL=	${WRKDIR}/INSTALL
PKGDEINSTALL=	${WRKDIR}/DEINSTALL
WRKSRC=		${WRKDIR}

USE_X_PREFIX=	yes

PLIST_SUB=	FONTSDIR=${FONTSDIR}

do-build:
	@(cd ${WRKSRC}; \
	    for i in ${BITMAP_FONTS_SIZE} ; do \
	        bdftopcf bitmap$${i}.bdf > bitmap$${i}.pcf ; \
	        ${GZIP_CMD} bitmap$${i}.pcf ; \
	    done ; \
	)
	@for file in INSTALL DEINSTALL; do \
		${SED} -e 's,%%FONTSDIR%%,${FONTSDIR},g' \
			< ${FILESDIR}/$${file}.tmpl > ${WRKDIR}/$${file}; \
	done

pre-install:
	@${SETENV} PKG_PREFIX=${X11BASE} \
		${SH} ${PKGREQ} ${PKGNAME} INSTALL

do-install:
	@(cd ${WRKSRC}; \
	    for i in ${BITMAP_FONTS_SIZE} ; do \
	        ${INSTALL_DATA} bitmap$${i}.pcf.gz ${X11BASE}/${FONTSDIR} ; \
	    done ; \
	)

post-install:
	@${SETENV} PKG_PREFIX=${X11BASE} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
