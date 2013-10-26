# Created by: Maurice Castro <maurice@serc.rmit.edu.au>
# $FreeBSD$

PORTNAME?=	R
PORTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES=	math lang
MASTER_SITES=	http://cran.r-project.org/%SUBDIR%/ \
		ftp://cran.r-project.org/pub/R/%SUBDIR%/ \
		http://cran.at.r-project.org/%SUBDIR%/ \
		http://cran.au.r-project.org/%SUBDIR%/ \
		http://cran.br.r-project.org/%SUBDIR%/ \
		http://cran.ch.r-project.org/%SUBDIR%/ \
		http://cran.es.r-project.org/%SUBDIR%/ \
		http://cran.dk.r-project.org/%SUBDIR%/ \
		http://cran.uk.r-project.org/%SUBDIR%/ \
		http://cran.us.r-project.org/%SUBDIR%/ \
		ftp://ftp.u-aizu.ac.jp/pub/lang/R/CRAN/%SUBDIR%/ \
		http://lib.stat.cmu.edu/R/CRAN/%SUBDIR%/ \
		http://cran.stat.ucla.edu/%SUBDIR%/ \
		http://probability.ca/cran/%SUBDIR%/
MASTER_SITE_SUBDIR=	src/base/R-${PORTVERSION:C|\..*||}
DISTNAME=	R-${PORTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT?=	A language for statistical computing and graphics

LICENSE=	GPLv2

BUILD_DEPENDS=		${LOCALBASE}/bin/gsed:${PORTSDIR}/textproc/gsed

CONFIGURE_ENV=		SED="${LOCALBASE}/bin/gsed" \
			ac_cv_have_decl_powl=yes ac_cv_have_decl_log1pl=yes

OPTIONS_DEFINE=		MISSING

MISSING_DESC=		use libmissing rather than libquadmath

.if defined(LIBRMATH_SLAVEPORT)
BUILD_WRKSRC=		${WRKSRC}/src/nmath/standalone
CONFIGURE_ARGS=		--disable-nls --with-ICU=no --with-cairo=no \
			--with-jpeglib=no --with-libpng=no --with-libtiff=no \
			--with-readline=no --with-tcltk=no --with-x=no \
			--without-libintl-prefix
CONFIGURE_ENV+=		ac_cv_header_iconv_h=no
PLIST_SUB=		RMATH_SOVERSION="${RMATH_SOVERSION}"
USE_LDCONFIG=		yes
.else # LIBRMATH_SLAVEPORT
ALL_TARGET=		all
INSTALL_TARGET =	install
CONFIGURE_ARGS =	--enable-memory-profiling rdocdir=${DOCSDIR} \
			--with-system-bzlib --with-system-zlib
CONFIGURE_ENV+=		FCFLAGS="${FFLAGS}" \
			INSTALL_DATA="${INSTALL} ${COPY} ${_SHROWNGRP} -m 644" \
			R_LD_LIBRARY_PATH="${R_LD_LIBRARY_PATH}" TAR="${TAR}"
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE+=	ATLAS ICU PCRE_PORT THREADS

ATLAS_DESC=		Use ATLAS instead of BLAS/LAPACK
ICU_DESC=		Use ICU for collation in multibyte locales
PCRE_PORT_DESC =	Use devel/pcre instead of the bundled PCRE

OPTIONS_DEFAULT+=	ICU PCRE_PORT THREADS
.if !defined(LIBR_SLAVEPORT)
RUN_DEPENDS+=		${LOCALBASE}/bin/gsed:${PORTSDIR}/textproc/gsed
USE_LDCONFIG=		${PREFIX}/lib/R/lib
NO_STAGE=	yes
#now only used to build the R.1 manpage:
USES+=			perl5
USE_PERL5=		build

MAN1=			R.1 Rscript.1

OPTIONS_DEFINE+=	GHOSTSCRIPT INFO_MANUALS JPEG LETTER_PAPER LIBR \
			PANGOCAIRO PDF_MANUALS PNG TCLTK TIFF X11

GHOSTSCRIPT_DESC=	[dev2]bitmap() graphics devices
INFO_MANUALS_DESC=	GNU info manuals
JPEG_DESC=		jpeg() graphics device
LETTER_PAPER_DESC=	US Letter paper
LIBR_DESC=		R shared library and a dynamically-linked R
PANGOCAIRO_DESC=	cairo and pango graphics support
PDF_MANUALS_DESC=	PDF manuals (requires TeX)
PNG_DESC=		png() graphics device
TCLTK_DESC=		tcltk package
X11_DESC=		X11() graphics device

OPTIONS_DEFAULT+=	GHOSTSCRIPT INFO_MANUALS JPEG LIBR PANGOCAIRO PNG \
			TCLTK TIFF X11

.endif # !LIBR_SLAVEPORT
PLIST_SUB=		R_SOVERSION="${R_SOVERSION}" \
			RBLAS_SOVERSION="${RBLAS_SOVERSION}" \
			RLAPACK_SOVERSION="${RLAPACK_SOVERSION}"
R_LD_LIBRARY_PATH=	${_GCC_RUNTIME}:${LOCALBASE}/lib
USES+=			iconv
.endif # LIBRMATH_SLAVEPORT
GNU_CONFIGURE=		yes
MAKE_JOBS_UNSAFE=	yes
R_SOVERSION=		1
RBLAS_SOVERSION=	2
RLAPACK_SOVERSION=	4
RMATH_SOVERSION=	0
USE_FORTRAN=		yes

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64" || ${ARCH} == "powerpc64"
PICFLAG?=		-fPIC
.else
PICFLAG?=		-fpic
.endif
.for flag in LD CXXLD
CONFIGURE_ENV +=	SHLIB_${flag}FLAGS="${PICFLAG}"
.endfor

.if ${PORT_OPTIONS:MMISSING}
LIB_DEPENDS+=		missing:${PORTSDIR}/math/libmissing
LIBM=			-lm -L${LOCALBASE}/lib -lmissing
LIBMH=			"missing_math.h"
.if defined(LIBRMATH_SLAVEPORT)
CPPFLAGS+=		-I${LOCALBASE}/include
.endif
.else
LIBM=			-lm -lquadmath
LIBMH=			<quadmath.h>
.endif

.if !defined(LIBRMATH_SLAVEPORT)
.if ${PORT_OPTIONS:MATLAS}
LIB_DEPENDS+=		atlas:${PORTSDIR}/math/atlas
BLAS?=			-lf77blas
LAPACK?=		-lalapack -lcblas
.else
BLAS?=			no
LAPACK?=		no
.endif
CONFIGURE_ARGS+=	--with-blas="${BLAS}" --with-lapack="${LAPACK}"
.if ${BLAS} == "no" || ${LAPACK} == "no"
PLIST_SUB+=		LAPACK=""
.else
PLIST_SUB+=		LAPACK="@comment "
.endif

.if ${PORT_OPTIONS:MICU}
LIB_DEPENDS+=		icui18n:${PORTSDIR}/devel/icu
CONFIGURE_ARGS+=	--with-ICU
.else
CONFIGURE_ARGS+=	--without-ICU
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=			gettext
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.if ${PORT_OPTIONS:MPCRE_PORT}
LIB_DEPENDS+=		pcre:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=	--with-system-pcre
.else
CONFIGURE_ARGS+=	--without-system-pcre
.endif

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=	--enable-threads=posix
.else
CONFIGURE_ARGS+=	--disable-threads
.endif

.if defined(LIBR_SLAVEPORT)

CONFIGURE_ARGS+=	--disable-BLAS-shlib --without-pic --without-x

.else # LIBR_SLAVEPORT

.if ${PORT_OPTIONS:MGHOSTSCRIPT}
USE_GHOSTSCRIPT_RUN=	yes
.endif

.if ${PORT_OPTIONS:MJPEG}
LIB_DEPENDS+=		jpeg:${PORTSDIR}/graphics/jpeg
CONFIGURE_ARGS+=	--with-jpeglib
.else
CONFIGURE_ARGS+=	--without-jpeglib
.endif

.if ${PORT_OPTIONS:MLETTER_PAPER}
CONFIGURE_ENV +=	R_PAPERSIZE=letter
.endif

.if ${PORT_OPTIONS:MLIBR}
CONFIGURE_ARGS+=	--enable-R-shlib
PLIST_SUB+=		LIBR=""
.else
PLIST_SUB+=		LIBR="@comment "
.endif

.if ${PORT_OPTIONS:MPANGOCAIRO}
USES+=			pkgconfig
USE_GNOME+=		pango
PLIST_SUB+=		PANGOCAIRO=""
.else
CONFIGURE_ARGS+=	--without-cairo
PLIST_SUB+=		PANGOCAIRO="@comment "
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=		png15:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=	--with-libpng
.else
CONFIGURE_ARGS+=	--without-libpng
.endif

.if ${PORT_OPTIONS:MTCLTK}
USE_TK =		84+
CONFIGURE_ARGS+=	--with-tcltk \
			--with-tcl-config=${TCL_LIBDIR}/tclConfig.sh \
			--with-tk-config=${TK_LIBDIR}/tkConfig.sh
PLIST_SUB+=		TCLTK=""
.else
CONFIGURE_ARGS+=	--without-tcltk
PLIST_SUB+=		TCLTK="@comment "
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=		tiff:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=	--with-libtiff
.else
CONFIGURE_ARGS+=	--without-libtiff
.endif

.if ${PORT_OPTIONS:MX11}
CONFIGURE_ARGS+=	--with-x
USE_XORG=		x11 xmu xt
PLIST_SUB+=		X11=""
.else
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=		X11="@comment "
.endif

.if ${PORT_OPTIONS:MINFO_MANUALS} && ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	info
INFO=		R-FAQ R-admin R-data R-exts R-intro R-lang
.endif

.if ${PORT_OPTIONS:MPDF_MANUALS} && ${PORT_OPTIONS:MDOCS}
BROKEN=			The PDF_MANUALS option cannot be used, because it\
			requires broken components of texlive
USE_TEX=		texlive pdftex:build
BUILD_DEPENDS +=	texi2dvi:${PORTSDIR}/print/texinfo
ALL_TARGET+=		pdf
CONFIGURE_ENV +=	INSTALL_INFO="${LOCALBASE}/bin/install-info" \
			MAKEINFO="${LOCALBASE}/bin/makeinfo"
INSTALL_TARGET+=	install-pdf
PLIST_SUB+=		PDF_MANUAL=""
.else
PLIST_SUB+=		PDF_MANUAL="@comment "
.endif
.endif # LIBR_SLAVEPORT
.endif # !LIBRMATH_SLAVEPORT

post-patch:
.if !${PORT_OPTIONS:MMISSING}
.if ${OSVERSION} < 1000016
	@${REINPLACE_CMD} -e 's/# define EXP expl/# define EXP(x) (long double)expq((__float128)(x))/' \
		${WRKSRC}/src/nmath/pnchisq.c
.endif
	@${REINPLACE_CMD} -Ee 's/(log)(1p)?l\(/(long double)\1\2q((__float128)/' \
		${WRKSRC}/src/nmath/dnbeta.c \
		${WRKSRC}/src/nmath/pnbeta.c
	@${REINPLACE_CMD} -Ee 's/powl\((.*)(long double)/(long double)powq((__float128)\1__float128/' \
		${WRKSRC}/src/main/format.c
.endif
	@${REINPLACE_CMD} -e \
	'\|#include <math.h>|{x;s|^.*$$|#include ${LIBMH}|;H;x;}' \
		${WRKSRC}/src/nmath/nmath.h
	@${REINPLACE_CMD} -e '\|LIBS=|s|-lrt ||' \
		-e '\|-lm[". ]|s|-lm|${LIBM}|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/src/nmath/standalone/Makefile.in \
		${WRKSRC}/src/unix/Makefile.in
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" \
		${WRKSRC}/configure \
		${WRKSRC}/src/scripts/javareconf
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|g" \
		${WRKSRC}/configure \
		${WRKSRC}/src/library/profile/Rprofile.unix \
		${WRKSRC}/src/scripts/javareconf
.if !defined(LIBRMATH_SLAVEPORT)
.if !${PORT_OPTIONS:MNLS}
	@(cd ${WRKSRC}/src/library/Recommended; \
	for tarfile in *.tgz *.tar.gz ; do \
	${TAR} -czf temptgz --exclude='*/po/*' @$$tarfile ; \
	${MV} temptgz $$tarfile ; \
	done)
	@${REINPLACE_CMD} -e '/ls -d $$(srcdir)\/inst/d' \
		${WRKSRC}/src/library/translations/Makefile.in
.endif

.if !${PORT_OPTIONS:MMISSING}
pre-configure:
	@if [ ! -f ${_GCC_RUNTIME}/libquadmath.a ] ; then \
	${PRINTF} "\n\n\n%s\n\n\n" "libquadmath is not available for your\
	compiler and architecture: please enable the MISSING option." ; \
	exit 1 ; fi
.endif

.if defined(LIBR_SLAVEPORT)
do-build:
.for d in include extra
	@(cd ${WRKSRC}/src/${d}; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} R)
.endfor
	@(cd ${WRKSRC}/src/main; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} Makefile Makedeps libR.a)

do-install:
	@${MKDIR} ${PREFIX}/lib/R/lib
	@${INSTALL_DATA} ${WRKSRC}/src/main/libR.a ${PREFIX}/lib/R/lib

.else # LIBR_SLAVEPORT

pre-configure-script:
	@${FIND} ${WRKSRC} \( -name '*.orig' -o -name '*.bak' \) -delete

check regression-test test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} LANGUAGE=en \
	LC_COLLATE=C LC_TIME=C ${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} \
	check)

check-all: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} LANGUAGE=en \
	LC_COLLATE=C LC_TIME=C ${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} \
	check-all)

post-install:
.for L in R Rblas Rlapack
	@(cd ${PREFIX}/lib/R/lib; if [ -f lib${L}.so ] ; then \
	${LN} -sf lib${L}.so lib${L}.so.${${L:U}_SOVERSION} ; fi)
.endfor
.if ${PORT_OPTIONS:MINFO_MANUALS} && ${PORT_OPTIONS:MDOCS}
	@(cd ${WRKSRC}/doc/manual; \
	for infofile in ${INFO}; do \
		${INSTALL_DATA} $${infofile}.info* ${PREFIX}/${INFO_PATH}/; \
	done)
.endif

.endif # LIBR_SLAVEPORT
.else # !LIBRMATH_SLAVEPORT
do-install:
	@${INSTALL_DATA} ${WRKSRC}/src/include/Rmath.h ${PREFIX}/include
	@${INSTALL_DATA} ${BUILD_WRKSRC}/libRmath.a ${PREFIX}/lib
	@${STRIP_CMD} ${BUILD_WRKSRC}/libRmath.so
	@${INSTALL_DATA} ${BUILD_WRKSRC}/libRmath.so \
	${PREFIX}/lib/libRmath.so.${RMATH_SOVERSION}
	@(cd ${PREFIX}/lib; ${LN} -sf libRmath.so.${RMATH_SOVERSION} libRmath.so)

check regression-test test: build
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} LANGUAGE=en \
	LC_COLLATE=C LC_TIME=C ${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} test; \
	${SETENV} LD_LIBRARY_PATH="${BUILD_WRKSRC}" ${BUILD_WRKSRC}/test)

.endif # !LIBRMATH_SLAVEPORT

.include <bsd.port.mk>
