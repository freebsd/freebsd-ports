# New ports collection makefile for:    gnuplot
# Version required:     3.7
# Date created:         May 18, 1999
# Whom:                 NAKAJI Hiroyuki
#
# $FreeBSD$
#

DISTNAME=	gnuplot37+-1.1.8
CATEGORIES=	japanese math graphics
MASTER_SITES=	ftp://ftp.ipc.chiba-u.ac.jp/pub/pub.yamaga/gnuplot+/3.7base/
DISTFILES=	gnuplot-3.7.tar.gz gnuplot3.7+1.1.8.patch.tar.gz

MAINTAINER=	nakaji@tutrp.tut.ac.jp

LIB_DEPENDS=    png.3:${PORTSDIR}/graphics/png \
		VFlib2.24:${PORTSDIR}/japanese/vflib
BUILD_DEPENDS=	${LOCALBASE}/lib/libgd.a:${PORTSDIR}/graphics/gd \
		${LOCALBASE}/lib/libttf.a:${PORTSDIR}/print/freetype

BROKEN=		gd upgrade

EXTRACT_ONLY=	gnuplot-3.7.tar.gz

USE_XLIB=	yes
USE_GMAKE=	yes
USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--exec-prefix=${PREFIX} \
		--includedir=${LOCALBASE}/include/ \
		--libdir=${LOCALBASE}/lib \
		--with-x --without-linux-vga \
		--with-gd=${LOCALBASE}/lib \
		--with-gnu-readline --with-lasergnu --with-png \
		--with-vflib=${LOCALBASE}/lib

MAN1=		gnuplot.1 lasergnu.1

WRKSRC=		${WRKDIR}/gnuplot-3.7
GP_DOCS=	${WRKSRC}/Copyright.plus \
		${WRKSRC}/History.plus \
		${WRKSRC}/INSTALL-J.unx.plus \
		${WRKSRC}/INSTALL-J.win.plus \
		${WRKSRC}/INSTALL.unx.plus \
		${WRKSRC}/INSTALL.win.plus \
		${WRKSRC}/README-J.plus \
		${WRKSRC}/README.plus \
		${WRKSRC}/gp+/plus-asc.dvi \
		${WRKSRC}/gp+/plus-ntt.dvi \
		${WRKSRC}/gp+/plus.tex

post-extract:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/gnuplot3.7+1.1.8.patch.tar.gz ${EXTRACT_AFTER_ARGS} -C ${WRKSRC}

pre-patch:
	cd ${WRKSRC}; ${PATCH} --quiet -E -p0 < ${WRKSRC}/gnuplot3.7+1.1.patch

post-patch:
	cd ${WRKSRC}; ${TOUCH} aclocal.m4
	cd ${WRKSRC}; ${TOUCH} configure

pre-build:
	find ${WRKSRC} \( -name \*.orig -o -name \*~ \) -exec ${RM} -f \{} \;

post-build:
	cd ${WRKSRC}/docs; ${GMAKE} info
	cd ${WRKSRC}/docs; ${PATCH} --quiet -E -p1 < ${FILESDIR}/gnuplot.info.diff

post-install:
	@test -d ${PREFIX}/share/doc/gnuplot+ || ${MKDIR} ${PREFIX}/share/doc/gnuplot+
	${INSTALL_DATA} ${GP_DOCS} ${PREFIX}/share/doc/gnuplot+
	${INSTALL_DATA} ${WRKSRC}/docs/gnuplot.info ${PREFIX}/info
	install-info ${PREFIX}/info/gnuplot.info ${PREFIX}/info/dir
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
