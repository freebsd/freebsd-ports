# New ports collection makefile for:	bitmap-font
# Date created:		23 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bitmap-font
PORTVERSION=	8.2
CATEGORIES=	x11-fonts elisp
MASTER_SITES=	ftp://ftp.jpl.org/pub/elisp/bitmap/
DISTNAME=	bitmap-mule-${PORTVERSION}

MAINTAINER=	shige@FreeBSD.org

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11/XFree86

# distfile version
BITMAP_FONT=	etl6x12-bitmap etl7x14-bitmap etl8x16-bitmap etl12x24-bitmap
FONTSDIR=	lib/X11/fonts/local
PKGINSTALL=     ${WRKDIR}/INSTALL
PKGDEINSTALL=   ${WRKDIR}/DEINSTALL

USE_X_PREFIX=	yes

PLIST_SUB=	FONTSDIR=${FONTSDIR}

do-build:
	@(cd ${WRKSRC}/font; \
	    for i in ${BITMAP_FONT} ; do \
	        bdftopcf $${i}.bdf > $${i}.pcf ; \
	        ${GZIP_CMD} $${i}.pcf ; \
	    done ; \
	)
	@for file in INSTALL DEINSTALL; do \
		${SED} -e 's,%%FONTSDIR%%,${FONTSDIR},g' \
			< ${FILESDIR}/$${file}.tmpl > ${WRKDIR}/$${file}; \
	done

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/REQ ${PKGNAME} INSTALL

do-install:
	@(cd ${WRKSRC}/font; \
	    for i in ${BITMAP_FONT} ; do \
	        ${INSTALL_DATA} $${i}.pcf.gz ${PREFIX}/${FONTSDIR} ; \
	    done ; \
	)

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
