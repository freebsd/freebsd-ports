PORTNAME=	giacxcas
DISTVERSION=	1.9.0-85
PORTREVISION=	7
CATEGORIES=	math
MASTER_SITES=	http://www-fourier.ujf-grenoble.fr/~parisse/debian/dists/stable/main/source/:giac \
		http://cocoa.dima.unige.it/cocoa/cocoalib/tgz/:cocoa \
		http://www-fourier.ujf-grenoble.fr/~parisse/giac/freebsd/
DISTFILES=	giac_${DISTVERSION}${EXTRACT_SUFX}:giac \
		CoCoALib-${COCOA_LIB_VERSION}.tgz:cocoa \
		fltk-giac.tar.gz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Computer algebra system
WWW=		https://www-fourier.ujf-grenoble.fr/~parisse/giac.html

LICENSE=	GPLv3 DOC
LICENSE_COMB=	multi
LICENSE_NAME_DOC=	French documentation
LICENSE_TEXT_DOC=	French documentation is for non-commercial use only
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING
LICENSE_PERMS_DOC=	dist-mirror pkg-mirror auto-accept
LICENSE_DISTFILES_DOC=	giac_${DISTVERSION}${EXTRACT_SUFX}

BROKEN_armv7=	compilation fails: constant expression evaluates to 61171872541 which cannot be narrowed to type 'long' [-Wc++11-narrowing]
BROKEN_i386=	compilation fails: constant expression evaluates to 61171872541 which cannot be narrowed to type 'long' [-Wc++11-narrowing]
BROKEN_powerpc=	compilation fails: constant expression evaluates to 61171872541 which cannot be narrowed to type 'long' [-Wc++11-narrowing]

BUILD_DEPENDS=	bash:shells/bash \
		hevea:textproc/hevea
LIB_DEPENDS=	libao.so:audio/libao \
		libboost_serialization.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libfontconfig.so:x11-fonts/fontconfig \
		libgsl.so:math/gsl \
		libglpk.so:math/glpk \
		libgmp.so:math/gmp \
		libecm.so:math/gmp-ecm \
		libmpfr.so:math/mpfr \
		libmpfi.so:math/mpfi \
		libpari.so:math/pari \
		libpng.so:graphics/png \
		libnauty.so:math/nauty \
		libcliquer.so:math/cliquer \
		libsamplerate.so:audio/libsamplerate
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		autoreconf blaslapack compiler:c++14-lang desktop-file-utils fortran \
		gettext gl gmake gnome jpeg libtool localbase ncurses perl5 \
		python readline shebangfix tex xorg
GNU_CONFIGURE=	yes
USE_CXXSTD=	c++11
USE_GL=		gl
USE_XORG=	x11 xcursor xext xfixes xft xi xinerama xrender
USE_TEX=	latex:build dvipsk:build
USE_PERL5=	run
USE_LDCONFIG=	yes
# Warning:  don't remove the USE_GCC without a runtime test *after* make install
#USE_GCC=	yes
CONFIGURE_ENV=	ac_cv_lib_X11_main=yes \
		ac_cv_lib_cocoa_main=yes \
		ac_cv_lib_fltk_gl_main=yes \
		ac_cv_lib_fltk_main=yes \
		ac_cv_lib_fltk_images_main=yes \
		ac_cv_lib_jpeg_main=yes
SHEBANG_FILES=	src/pgiac micropython-1.12/docs/conf.py

INSTALL_TARGET=	install-strip

COCOA_LIB_VERSION=	0.99818

CPPFLAGS+=	-I${COCOALIB-GIAC}/include \
		-I${FLTKDEV-GIAC} \
		-Wno-narrowing
LDFLAGS+=	-L${COCOALIB-GIAC}/lib \
		-L${FLTKDEV-GIAC}/lib \
		-lintl

WRKSRC=		${WRKDIR}/giac-${DISTVERSION:C/-[0-9]*//}
FLTKDEV-GIAC=	${WRKDIR}/fltk-1.3.0
COCOALIB-GIAC=	${WRKDIR}/CoCoALib-${COCOA_LIB_VERSION}
TEST_TARGET=	check

DATADIR=	${PREFIX}/share/giac
DOCSDIR=	${PREFIX}/share/doc/giac
EXAMPLESDIR=	${PREFIX}/share/examples/giac

INFO=		giac_es giac_us

OPTIONS_DEFINE=	DOCS EXAMPLES

#NB: built of giacxcas with USE_GCC and nlt is successfull if the ntl port is also
#    installed  with USE_GCC
CONFIGURE_ARGS+=	--disable-ntl
CONFIGURE_ARGS+=	--disable-micropy # it causes SEGV in xcas in the nlr_push call from execute_from_lexer@main.c

PORTDOCS=	*
PORTEXAMPLES=	*

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
	${SED} -i ".orig" -Ee 's|char \*last = style \+ strlen\(style\) - 2|char *last = pretty|' \
		-Ee 's|\*style = 0|last = style + strnlen(style, ENDOFBUFFER) - 2; *style = 0|' \
		${FLTKDEV-GIAC}/src/fl_set_fonts_xft.cxx

pre-configure:
	${REINPLACE_CMD} -e 's|^protected:|public:|' ${FLTKDEV-GIAC}/FL/Fl_Widget.H
.for f in icas.cc path.h
	${REINPLACE_CMD} -e 's|/usr/local/share/giac/doc|${DOCSDIR}|' \
		${WRKSRC}/src/${f}
.endfor
	${FIND} ${WRKSRC}/doc -type f | ${XARGS} ${GREP} -l 'share/giac/doc' | \
		${XARGS} ${REINPLACE_CMD} -e 's|/usr/local/share/giac/doc|${DOCSDIR}|'
	${FIND} ${WRKSRC}/micropython-1.12 -type f | ${XARGS}	\
		${GREP} -l "/usr/bin/env python3" | ${XARGS}	\
		${REINPLACE_CMD} -e 's|/usr/bin/env python3|${PYTHON_CMD}|'
	${FIND} ${WRKSRC}/micropython-1.12 -type f | ${XARGS}	\
		${GREP} -l "python3 \|'python3'\|= python3\|^python3" | ${XARGS}	\
		${REINPLACE_CMD} -e "s|python3 |${PYTHON_CMD} |;s|'python3'|'${PYTHON_CMD}'|"	\
			-e "s|= python3|= ${PYTHON_CMD}|;s|^python3|${PYTHON_CMD}|"
	@(cd ${COCOALIB-GIAC} && ${SETENV} ${CONFIGURE_ENV} ./configure \
		--with-cxx="${CXX}")
	@(cd ${FLTKDEV-GIAC} && ${SETENV} ${CONFIGURE_ENV} ./configure \
		--prefix=${FLTKDEV-GIAC} \
		CXX="${CXX}" CXXFLAGS="${CXXFLAGS}")

post-configure:	# malloc.h on 13-CURRENT is missing mallinfo and compilation fails after it is discovered
	@${FIND} ${WRKSRC} -name config.h | ${XARGS} ${REINPLACE_CMD} -e 's|#define HAVE_MALLOC_H 1|/* #undef HAVE_MALLOC_H */|'

pre-build:
	@cd ${COCOALIB-GIAC} && ${DO_MAKE_BUILD} \
		CXXFLAGS_SPECIFIC="${CXXFLAGS}" library
	@cd ${FLTKDEV-GIAC}/src && ${DO_MAKE_BUILD}
	@cd ${WRKSRC}/src && ${CXX} -o mkjs mkjs.cc

post-install-EXAMPLES-on:
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} "Exemples [a-z]*" \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
