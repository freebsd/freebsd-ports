# New ports collection makefile for:    gnuplot
# Date created:         May 18, 1999
# Whom:                 NAKAJI Hiroyuki
#
# $FreeBSD$
#

PORTNAME=	gnuplot371+
PORTVERSION=	1.1.9
CATEGORIES=	math japanese graphics
MASTER_SITES=	ftp://ftp.ipc.chiba-u.ac.jp/pub/pub.yamaga/gnuplot+/3.7base/ \
		ftp://ftp.hipecs.hokudai.ac.jp/pub/GNU/jp/pub.yamaga/gnuplot+/3.7base/ \
		ftp://ftp.tohoku.ac.jp/mirror/gnuplot+/3.7base/ \
		ftp://ftp.win.ne.jp/pub/graphics/gnuplot/gnuplot+/3.7base/ \
		ftp://ftp.rc.tutrp.tut.ac.jp/pub/mirror/gnuplot+/3.7base/
DISTFILES=	gnuplot-3.7.1.tar.gz gnuplot3.7.1+1.1.9.patch.tar.gz \
		gnuplot3.7.1+1.1.9.bugfix
EXTRACT_ONLY=	gnuplot-3.7.1.tar.gz

MAINTAINER=	nakaji@tutrp.tut.ac.jp

LIB_DEPENDS=	png.3:${PORTSDIR}/graphics/png \
		VFlib2.24:${PORTSDIR}/japanese/vflib
.if defined(WITH_JP)
BUILD_DEPENDS=	${LOCALBASE}/lib/libgd.a:${PORTSDIR}/japanese/gd \
		${LOCALBASE}/lib/libttf.a:${PORTSDIR}/print/freetype
.else
LIB_DEPENDS=	gd.1:${PORTSDIR}/graphics/gd
BUILD_DEPENDS=	${LOCALBASE}/lib/libttf.a:${PORTSDIR}/print/freetype
.endif

USE_XLIB=	yes
USE_GMAKE=	yes
USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--exec-prefix=${PREFIX} \
		--includedir=${LOCALBASE}/include/ \
		--libdir=${LOCALBASE}/lib \
		--with-x --without-linux-vga \
		--with-gd=${LOCALBASE}/lib \
		--with-readline=gnu --with-lasergnu --with-png \
		--with-vflib=${LOCALBASE}/lib

MAN1=		gnuplot.1 lasergnu.1

WRKSRC=		${WRKDIR}/gnuplot-3.7.1
GP_DOCS=	${WRKSRC}/Copyright.plus \
		${WRKSRC}/History.plus \
		${WRKSRC}/INSTALL-J.unx.plus \
		${WRKSRC}/INSTALL-J.win.plus \
		${WRKSRC}/INSTALL.unx.plus \
		${WRKSRC}/INSTALL.win.plus \
		${WRKSRC}/README-J.plus \
		${WRKSRC}/README.plus \
		${WRKSRC}/gp+/plus.dvi \
		${WRKSRC}/gp+/plus.pdf \
		${WRKSRC}/gp+/plus.ps \
		${WRKSRC}/gp+/plus.tex

pre-fetch:
.ifndef WITH_JP
	@echo "**********************************************************"
	@echo "If you want handle Japanese TrueType font, define WITH_JP."
	@echo "**********************************************************"
.endif

post-extract:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/gnuplot3.7.1+1.1.9.patch.tar.gz ${EXTRACT_AFTER_ARGS} -C ${WRKSRC}

pre-patch:
	${PATCH} ${PATCH_ARGS} < ${WRKSRC}/gnuplot3.7+1.1.patch
	${PATCH} ${PATCH_ARGS} < ${DISTDIR}/gnuplot3.7.1+1.1.9.bugfix

post-patch:
	cd ${WRKSRC}; ${TOUCH} aclocal.m4
	cd ${WRKSRC}; ${TOUCH} configure

pre-build:
	find ${WRKSRC} \( -name \*.orig -o -name \*~ \) -exec ${RM} -f \{} \;

post-build:
	cd ${WRKSRC}/docs; ${GMAKE} info

post-install:
	@test -d ${PREFIX}/share/doc/gnuplot+ || ${MKDIR} ${PREFIX}/share/doc/gnuplot+
	${INSTALL_DATA} ${GP_DOCS} ${PREFIX}/share/doc/gnuplot+
	${INSTALL_DATA} ${WRKSRC}/docs/gnuplot.info ${PREFIX}/info
	install-info ${PREFIX}/info/gnuplot.info ${PREFIX}/info/dir
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
