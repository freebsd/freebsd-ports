# New ports collection makefile for:    gnuplot
# Date created:         May 18, 1999
# Whom:                 NAKAJI Hiroyuki
#
# $FreeBSD$
#

PORTNAME=	gnuplot371+
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	math japanese graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.yama-ga.com/gnuplot/:patch \
		http://www.h2.dion.ne.jp/~yamaga/gnuplot/:patch
MASTER_SITE_SUBDIR=	gnuplot
DISTFILES=	gnuplot-3.7.1.tar.gz \
		gnuplot3.7.1+${PORTVERSION}.patch.tar.gz:patch
EXTRACT_ONLY=	gnuplot-3.7.1.tar.gz

MAINTAINER=	nakaji@jp.freebsd.org
COMMENT=	A command-driven interactive function plotting program

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		VFlib2.24:${PORTSDIR}/japanese/vflib

USE_FREETYPE=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
USE_AUTOCONF_VER=	213
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

post-extract:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/gnuplot3.7.1+${PORTVERSION}.patch.tar.gz ${EXTRACT_AFTER_ARGS} -C ${WRKSRC}

pre-patch:
	${PATCH} ${PATCH_ARGS} < ${WRKSRC}/gnuplot3.7+1.2.patch

post-patch:
	cd ${WRKSRC}; ${TOUCH} aclocal.m4
	cd ${WRKSRC}; ${TOUCH} configure

pre-build:
	${FIND} ${WRKSRC} \( -name \*.orig -o -name \*~ \) -exec ${RM} -f \{} \;

post-build:
	cd ${WRKSRC}/docs; ${GMAKE} info

post-install:
	@test -d ${PREFIX}/share/doc/gnuplot+ || ${MKDIR} ${PREFIX}/share/doc/gnuplot+
	${INSTALL_DATA} ${GP_DOCS} ${PREFIX}/share/doc/gnuplot+
	${INSTALL_DATA} ${WRKSRC}/docs/gnuplot.info ${PREFIX}/info
	install-info ${PREFIX}/info/gnuplot.info ${PREFIX}/info/dir
	${MKDIR} ${PREFIX}/share/examples/gnuplot+
	${INSTALL_DATA} ${WRKSRC}/demo/* ${PREFIX}/share/examples/gnuplot+

.include <bsd.port.mk>
