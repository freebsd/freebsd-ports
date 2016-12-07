# Created by: Frederic Han <han@math.jussieu.fr>
# $FreeBSD$

PORTNAME=	giacxcas
DISTVERSION=	1.2.2-57
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www-fourier.ujf-grenoble.fr/~parisse/debian/dists/stable/main/source/:giac \
		http://www-fourier.ujf-grenoble.fr/~parisse/giac/freebsd/
DISTFILES=	giac_${DISTVERSION}${EXTRACT_SUFX}:giac \
		CoCoALib-0.9950.tgz \
		fltk-giac.tar.gz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Computer algebra system

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libgmp.so:math/gmp \
		libpng.so:graphics/png \
		libpari.so:math/pari \
		libmpfr.so:math/mpfr \
		libgsl.so:math/gsl
RUN_DEPENDS=	xdg-open:devel/xdg-utils

NO_CDROM=	French documentation is for non-commercial use only

GNU_CONFIGURE=	yes
USES=		blaslapack desktop-file-utils fortran gettext gmake jpeg \
		libtool readline shebangfix
USE_GL=		gl
USE_XORG=	x11 xcursor xext xft xi xinerama
USE_TEX=	latex:build dvipsk:build
USE_LDCONFIG=	yes
# Warning:  don't remove the USE_GCC without a runtime test *after* make install
USE_GCC=	yes
CONFIGURE_ENV=	ac_cv_lib_X11_main=yes \
		ac_cv_lib_cocoa_main=yes \
		ac_cv_lib_fltk_gl_main=yes \
		ac_cv_lib_fltk_main=yes \
		ac_cv_lib_fltk_images_main=yes \
		ac_cv_lib_jpeg_main=yes
SHEBANG_FILES=	src/pgiac
INSTALL_TARGET=	install-strip
INSTALLS_ICONS=	yes

CXXFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${COCOALIB-GIAC}/include \
		-I${FLTKDEV-GIAC} \
		-I${LOCALBASE}/include
LDFLAGS+=	-L${COCOALIB-GIAC}/lib \
		-L${FLTKDEV-GIAC}/lib \
		-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/giac-${DISTVERSION:C/-[0-9]*//}
FLTKDEV-GIAC=	${WRKDIR}/fltk-1.3.0
COCOALIB-GIAC=	${WRKDIR}/CoCoALib-0.9950

DATADIR=	${PREFIX}/share/giac
DOCSDIR=	${PREFIX}/share/doc/giac
EXAMPLESDIR=	${PREFIX}/share/examples/giac

INFO=		giac_es giac_us

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

#NB: built of giacxcas with USE_GCC and nlt is successfull if the ntl port is also
#    installed  with USE_GCC
.if ${OSVERSION} >= 1000000
CONFIGURE_ARGS+=	--disable-ntl
.else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libntl.a:math/ntl
.endif

post-extract:
	@${FIND} ${WRKSRC}/examples/Exemples -name "._*" -delete

post-patch:
	@${GREP} -Rl --null /bin/bash ${COCOALIB-GIAC} | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's|/bin/bash|/usr/bin/env bash|'
	@${REINPLACE_CMD} -e '/^SUBDIR/s|examples||' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/bin|${LOCALBASE}/bin|' \
		${WRKSRC}/xcas.applications
	@${REINPLACE_CMD} -e 's|cp -f \*|$$(INSTALL_DATA) WARNINGS [a-z]*|' \
		${WRKSRC}/doc/el/*/Makefile.in
	@${REINPLACE_CMD} -e '/browser=/s|"mozilla"|"xdg-open"|' \
		${WRKSRC}/src/global.cc
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} \
		${REINPLACE_CMD} -e 's|$$(prefix)/share/giac/doc|$$(docdir)|'
	@${FIND} ${COCOALIB-GIAC} -name "Makefile" | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|\($$(MAKE) \)-s |\1|; s|\([[:blank:]]\)@|\1|'
	@${REINPLACE_CMD} -e '/.SILENT:/s|^|#|' \
		${FLTKDEV-GIAC}/makeinclude.in

pre-configure:
	@(cd ${COCOALIB-GIAC} && ${SETENV} ${CONFIGURE_ENV} ./configure \
		--with-libgmp=${LOCALBASE}/lib/libgmp.a \
		--with-cxx="${CXX}")
	@(cd ${FLTKDEV-GIAC} && ${SETENV} ${CONFIGURE_ENV} ./configure \
		--prefix=${FLTKDEV-GIAC} \
		CXX="${CXX}" CXXFLAGS="${CXXFLAGS}")

pre-build:
	@(cd ${COCOALIB-GIAC} && ${DO_MAKE_BUILD} \
		CXXFLAGS_SPECIFIC="${CXXFLAGS}" library)
	@(cd ${FLTKDEV-GIAC}/src && ${DO_MAKE_BUILD})

post-install-DOCS-on:
	@${LN} -sf ../doc/giac ${STAGEDIR}${DATADIR}/doc

post-install-EXAMPLES-on:
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} "Exemples [a-z]*" \
		${STAGEDIR}${EXAMPLESDIR})
	@${LN} -sf ../examples/giac ${STAGEDIR}${DATADIR}/examples

.include <bsd.port.mk>
