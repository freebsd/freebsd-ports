# Created by: Maurice Castro <maurice@serc.rmit.edu.au>
# $FreeBSD$

PORTNAME?=	R
PORTVERSION=	3.3.0
PORTREVISION=	2
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

MAINTAINER=	bf@FreeBSD.org
COMMENT?=	Language for statistical computing and graphics

LICENSE=	GPLv2

BUILD_DEPENDS=		${LOCALBASE}/bin/gsed:textproc/gsed \
			texi2dvi:print/texinfo
LIB_DEPENDS=		libcurl.so:ftp/curl

CONFIGURE_ENV=		LIBR_LDFLAGS="${LDFLAGS}" OBJC="${CC}" \
			SED="${LOCALBASE}/bin/gsed" \
			ac_cv_have_decl_powl=yes ac_cv_have_decl_log1pl=yes

OPTIONS_DEFINE=		MISSING DOCS LTO OPENMP LONGDOUBLE

MISSING_DESC=		use libmissing rather than libquadmath
LTO_DESC=		Try to produce faster code through LTO
LONGDOUBLE_DESC=	Enable use of long double data type
LTO_CONFIGURE_ENABLE=	lto
OPENMP_CONFIGURE_ENABLE=	openmp
LONGDOUBLE_CONFIGURE_ENABLE=	long-double

OPTIONS_SINGLE=		BLAS
OPTIONS_SINGLE_BLAS=	RBLAS ATLAS OPENBLAS NETLIB
OPTIONS_DEFAULT=	OPENBLAS

RBLAS_DESC=		Use internal blas implementation

OPENBLAS_USES=		blaslapack:openblas
NETLIB_USES=		blaslapack:netlib
ATLAS_USES=		blaslapack:atlas
RBLAS_CONFIGURE_ON=	--without-blas --without-lapack
RBLAS_CONFIGURE_OFF=	--with-blas="-L${LOCALBASE}/lib ${BLASLIB}" \
			--with-lapack="${LAPACKLIB}"

OPTIONS_SUB=		RBLAS

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
INSTALL_TARGET=		install-strip
CONFIGURE_ARGS=		--enable-memory-profiling rdocdir=${DOCSDIR} \
			--with-system-bzlib --with-system-zlib
CONFIGURE_ENV+=		FCFLAGS="${FFLAGS}" \
			R_LD_LIBRARY_PATH="${R_LD_LIBRARY_PATH}" TAR="${TAR}"
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE+=	ICU PCRE_PORT THREADS

ICU_DESC=		Use ICU for collation in multibyte locales
PCRE_PORT_DESC=		Use devel/pcre instead of the bundled PCRE

OPTIONS_DEFAULT+=	ICU PCRE_PORT THREADS
.if !defined(LIBR_SLAVEPORT)
RUN_DEPENDS+=		${LOCALBASE}/bin/gsed:textproc/gsed
USE_LDCONFIG=		${PREFIX}/lib/R/lib
#now only used to build the R.1 manpage:
USES+=			perl5
USE_PERL5=		build

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

OPTIONS_DEFAULT+=	GHOSTSCRIPT INFO_MANUALS JPEG LTO LIBR OPENMP \
			PANGOCAIRO PNG TCLTK TIFF X11

OPTIONS_DEFAULT_armv6+=		MISSING
OPTIONS_DEFAULT_powerpc+=	MISSING
OPTIONS_DEFAULT_powerpc64+=	MISSING
OPTIONS_DEFAULT_sparc64+=	MISSING

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
USES+=			fortran

.include "compiler.mk"
.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64" || ${ARCH} == "powerpc64"
PICFLAG?=		-fPIC
.else
PICFLAG?=		-fpic
.endif
.for flag in LD CXXLD
CONFIGURE_ENV +=	SHLIB_${flag}FLAGS="${PICFLAG}"
.endfor

.if ${OSVERSION} > 1000052 && \
(${ARCH} == amd64 || ${ARCH} == i386 || ${ARCH} == ia64 || ${ARCH} == pc98 || ${ARCH} == sparc64)
.for _f in coshl erfcl erfl lgammal powl sinhl tanhl tgammal
CFLAGS+=	-fno-builtin-${_f}
LDFLAGS+=	-fno-builtin-${_f}
.endfor
.endif

.if ${PORT_OPTIONS:MMISSING}
.for _f in acos asin atan cos cosh exp log pow sin sinh tan tanh
CONFIGURE_ENV+=		ac_cv_have_decl_c${_f}=yes
.endfor
LIB_DEPENDS+=		libmissing.so:math/libmissing
LIBM=			-L${LOCALBASE}/lib -lmissing -lm
LIBMH=			"missing_math.h"
.if defined(LIBRMATH_SLAVEPORT)
CPPFLAGS+=		-I${LOCALBASE}/include
.endif
.else
LIBM=			-lquadmath -lm
LIBMH=			<quadmath.h>
.endif

.if !defined(LIBRMATH_SLAVEPORT)

.if ${PORT_OPTIONS:MICU}
LIB_DEPENDS+=		libicui18n.so:devel/icu
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
LIB_DEPENDS+=		libpcre.so:devel/pcre
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
USES+=			readline

.else # LIBR_SLAVEPORT

.if ${PORT_OPTIONS:MGHOSTSCRIPT}
USES+=			ghostscript
.endif

.if ${PORT_OPTIONS:MJPEG}
USES+=			jpeg
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
USE_GNOME+=		pango cairo
PLIST_SUB+=		PANGOCAIRO=""
.else
CONFIGURE_ARGS+=	--without-cairo
PLIST_SUB+=		PANGOCAIRO="@comment "
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=		libpng.so:graphics/png
CONFIGURE_ARGS+=	--with-libpng
.else
CONFIGURE_ARGS+=	--without-libpng
.endif

.if ${PORT_OPTIONS:MTCLTK}
USES+=			tk:84+
CONFIGURE_ARGS+=	--with-tcltk \
			--with-tcl-config=${TCL_LIBDIR}/tclConfig.sh \
			--with-tk-config=${TK_LIBDIR}/tkConfig.sh
PLIST_SUB+=		TCLTK=""
.else
CONFIGURE_ARGS+=	--without-tcltk
PLIST_SUB+=		TCLTK="@comment "
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=		libtiff.so:graphics/tiff
CONFIGURE_ARGS+=	--with-libtiff
.else
CONFIGURE_ARGS+=	--without-libtiff
.endif

.if ${PORT_OPTIONS:MX11}
CONFIGURE_ARGS+=	--with-x
USE_XORG=		ice sm x11 xext xmu xscrnsaver xt
PLIST_SUB+=		X11=""
.else
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=		X11="@comment "
.endif

.if ${PORT_OPTIONS:MINFO_MANUALS} && ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	info
CONFIGURE_ENV+=	INSTALL_INFO="${LOCALBASE}/bin/install-info" \
		MAKEINFO="${LOCALBASE}/bin/makeinfo"
INFO=		R-FAQ R-admin R-data R-exts R-intro R-lang
.endif

.if ${PORT_OPTIONS:MPDF_MANUALS} && ${PORT_OPTIONS:MDOCS}
USE_TEX=		texlive dvipsk kpathsea pdftex
#BUILD_DEPENDS +=	texi2dvi:print/texinfo
ALL_TARGET+=		pdf
CONFIGURE_ENV +=	INSTALL_INFO="${LOCALBASE}/bin/install-info" \
			MAKEINFO="${LOCALBASE}/bin/makeinfo"
INSTALL_TARGET+=	install-pdf
PLIST_SUB+=		PDF_MANUAL=""
.else
.for _b in KPSEWHICH MAKEINDEX PDFLATEX PDFTEX TEX TEXI2DVI
CONFIGURE_ENV+=		ac_cv_path_${_b}=""
.endfor
PLIST_SUB+=		PDF_MANUAL="@comment "
.endif
.endif # LIBR_SLAVEPORT
.endif # !LIBRMATH_SLAVEPORT

post-patch:
	@${REINPLACE_CMD} -e '\|LIBS=|s|-lrt ||' \
		-e '\|-lm[". ]|s|-lm|${LIBM}|' \
		${WRKSRC}/configure
.if !${PORT_OPTIONS:MMISSING}
.if ${OSVERSION} < 1000016
	@${REINPLACE_CMD} -e 's/# define EXP expl/# define EXP(x) (long double)expq((__float128)(x))/' \
		${WRKSRC}/src/nmath/pnchisq.c\
		${WRKSRC}/src/nmath/pgamma.c
	@${REINPLACE_CMD} -e 's/# define LOG logl/# define LOG(x) (long double)logq((__float128)(x))/' \
		${WRKSRC}/src/nmath/pnchisq.c\
		${WRKSRC}/src/nmath/pgamma.c

.endif
.if ${OSVERSION} < 1000034
	@${REINPLACE_CMD} -Ee 's/(log)(1p)?l\(/(long double)\1\2q((__float128)/' \
		${WRKSRC}/src/nmath/dnbeta.c \
		${WRKSRC}/src/nmath/pnbeta.c
.endif
	@${REINPLACE_CMD} -Ee 's/powl\((.*)(long double)/(long double)powq((__float128)\1__float128/' \
		${WRKSRC}/src/main/format.c
.else
.if ${OSVERSION} > 1000052 && \
(${ARCH} == amd64 || ${ARCH} == i386 || ${ARCH} == ia64 || ${ARCH} == pc98 || ${ARCH} == sparc64)
	@${REINPLACE_CMD} -e '\|^FLIBS="$$ac_cv_f77_libs"|s|"|&${LIBM} |' \
		${WRKSRC}/configure
.endif
	@${REINPLACE_CMD} -e \
	'\|#[[:blank:]]*include[[:blank:]]*<complex.h>|{x;s|^.*$$|#include "missing_complex.h"|;H;x;}' \
		${WRKSRC}/src/main/complex.c
.endif
	@${REINPLACE_CMD} -e \
	'\|#[[:blank:]]*include[[:blank:]]*<math.h>|{x;s|^.*$$|#include ${LIBMH}|;H;x;}' \
		${WRKSRC}/src/nmath/nmath.h \
		${WRKSRC}/src/include/Rmath.h0.in
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/src/nmath/standalone/Makefile.in \
		${WRKSRC}/src/unix/Makefile.in
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|g" \
		${WRKSRC}/configure \
		${WRKSRC}/src/library/profile/Rprofile.unix \
		${WRKSRC}/src/scripts/javareconf.in
.if !defined(LIBRMATH_SLAVEPORT)
.if !${PORT_OPTIONS:MNLS}
	@(cd ${WRKSRC}/src/library/Recommended; \
	for tarfile in *.tgz *.tar.gz ; do \
	${TAR} -czf temptgz --exclude='*/po/*' @$$tarfile ; \
	${MV} temptgz $$tarfile ; \
	done)
	@${REINPLACE_CMD} -e '/ls -d $$srcdir\/inst/d' \
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
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/R/lib
	${INSTALL_DATA} ${WRKSRC}/src/main/libR.a ${STAGEDIR}${PREFIX}/lib/R/lib

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
	@if [ -d ${STAGEDIR}${PREFIX}/lib/R/lib ] ; then \
	cd ${STAGEDIR}${PREFIX}/lib/R/lib; if [ -f lib${L}.so ] ; then \
	${LN} -sf lib${L}.so lib${L}.so.${${L:tu}_SOVERSION} ; fi; fi
.endfor
.if ${PORT_OPTIONS:MINFO_MANUALS} && ${PORT_OPTIONS:MDOCS}
	@(cd ${WRKSRC}/doc/manual; \
	for infofile in ${INFO}; do \
		${INSTALL_DATA} $${infofile}.info* ${STAGEDIR}${PREFIX}/${INFO_PATH}/; \
	done)
.endif

.endif # LIBR_SLAVEPORT
.else # !LIBRMATH_SLAVEPORT
do-install:
	${INSTALL_DATA} ${WRKSRC}/src/include/Rmath.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${BUILD_WRKSRC}/libRmath.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${BUILD_WRKSRC}/libRmath.so \
	${STAGEDIR}${PREFIX}/lib/libRmath.so.${RMATH_SOVERSION}
	@(cd ${STAGEDIR}${PREFIX}/lib; ${LN} -sf libRmath.so.${RMATH_SOVERSION} libRmath.so)

check regression-test test: build
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} LANGUAGE=en \
	LC_COLLATE=C LC_TIME=C ${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} test; \
	${SETENV} LD_LIBRARY_PATH="${BUILD_WRKSRC}" ${BUILD_WRKSRC}/test)

.endif # !LIBRMATH_SLAVEPORT

.include <bsd.port.mk>
