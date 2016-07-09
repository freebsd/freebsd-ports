# Created by: Maurice Castro <maurice@serc.rmit.edu.au>
# $FreeBSD$

PORTNAME=		R
PORTVERSION=		3.3.1
PORTREVISION=		2
CATEGORIES=		math lang
MASTER_SITES=		http://cran.r-project.org/%SUBDIR%/ \
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

MAINTAINER=		jrm@ftfl.ca
COMMENT=		Language for statistical computing and graphics

LICENSE=		GPLv2

LIB_DEPENDS=		libcurl.so:ftp/curl \
			libpcre.so:devel/pcre
BUILD_DEPENDS=		texi2dvi:print/texinfo

GNU_CONFIGURE=		yes
USES=			fortran iconv objc:compiler
USE_LDCONFIG=		${PREFIX}/lib/R/lib

CONFIGURE_ARGS=		--disable-java --enable-memory-profiling \
			rdocdir=${DOCSDIR}

INSTALL_TARGET=		install-strip

OPTIONS_DEFINE=		DOCS ICU INFO LETTER LIBR LDOUBLE LTO MISSING NLS \
			OPENMP THREADS X11

OPTIONS_GROUP=		NEEDX11
OPTIONS_GROUP_NEEDX11=	GHOSTSCRIPT JPEG CAIROPANGO PDF PNG TCLTK TIFF

OPTIONS_SINGLE=		BLAS
OPTIONS_SINGLE_BLAS=	ATLAS OPENBLAS NETLIB RBLAS

OPTIONS_SUB=		YES

ATLAS_DESC=		ATLAS BLAS implementation
GHOSTSCRIPT_DESC=	Graphics Device for Bitmap Files via Ghostscript
CAIROPANGO_DESC=	Cairo graphics device and Pango multi-language text
INFO_DESC=		GNU info manuals
JPEG_DESC=		JPEG graphics device
LDOUBLE_DESC=		Enable long double data type
LETTER_DESC=		US Letter paper
LIBR_DESC=		Build dynamic (shared) R library
LTO_DESC=		Try to produce faster code through LTO
MISSING_DESC=		Use libmissing rather than libquadmath
NEEDX11_DESC=		X11-Implying Options
NETLIB_DESC=		Netlib BLAS implementation
OPENBLAS_DESC=		OpenBLAS BLAS implementation
PDF_DESC=		PDF manuals (requires TeX)
PNG_DESC=		PNG graphics device
RBLAS_DESC=		Use R-bundled BLAS implementation
X11_DESC=		X11 graphics device

OPTIONS_DEFAULT=	GHOSTSCRIPT ICU INFO JPEG LTO LIBR OPENBLAS OPENMP \
			CAIROPANGO PNG TCLTK TIFF THREADS X11

OPTIONS_DEFAULT_armv6+=		MISSING
OPTIONS_DEFAULT_powerpc+=	MISSING
OPTIONS_DEFAULT_powerpc64+=	MISSING
OPTIONS_DEFAULT_sparc64+=	MISSING

ATLAS_USES=		blaslapack:atlas

DOC_BUILD_DEPENDS=	texi2any:print/texinfo

GHOSTSCRIPT_IMPLIES=	X11
GHOSTSCRIPT_USES=	ghostscript

ICU_CONFIGURE_WITH=	ICU
ICU_LIB_DEPENDS=	libicui18n.so:devel/icu

INFO_IMPLIES=		DOCS
INFO_INSTALL_TARGET=	install-info
INFO_INFO=		R-FAQ R-admin R-data R-exts R-ints R-intro R-lang

JPEG_IMPLIES=		X11
JPEG_CONFIGURE_WITH=	jpeglib

LETTER_CONFIGURE_ENV=	R_PAPERSIZE=letter

LIBR_CONFIGURE_ENABLE=	R-shlib

LDOUBLE_CONFIGURE_ENABLE=long-double

LTO_CONFIGURE_ENABLE=	lto

.for i in acos asin atan cos cosh exp log pow sin sinh tan tanh
MISSING_CONFIGURE_ENV+=	ac_cv_have_decl_c${i}=yes
.endfor
MISSING_LIB_DEPENDS=	libmissing.so:math/libmissing
MISSING_VARS=		LIBM="-L${LOCALBASE}/lib -lmissing -lm" \
			LIBMH=<missing_math.h>
MISSING_VARS_OFF=	LIBM='-lquadmath -lm' \
			LIBMH=<quadmath.h>

NETLIB_USES=		blaslapack:netlib

NLS_CONFIGURE_OFF=	--disable-nls
NLS_USES=		gettext

OPENBLAS_USES=		blaslapack:openblas

OPENMP_CONFIGURE_ENABLE=openmp

CAIROPANGO_IMPLIES=	X11
CAIROPANGO_CONFIGURE_WITH=cairo
CAIROPANGO_USES=	gettext jpeg pkgconfig
CAIROPANGO_USE=		gnome=pango,cairo

PDF_IMPLIES=		DOCS X11
PDF_USE=		tex=dvipsk:build,kpathsea:build,pdftex:build
PDF_INSTALL_TARGET=	install-pdf
.for i in KPSEWHICH MAKEINDEX PDFLATEX PDFTEX TEX TEXI2DVI
PDF_CONFIGURE_ENV_OFF+=	ac_cv_path_${i}=""
.endfor

PNG_IMPLIES=		X11
PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_WITH=	libpng

RBLAS_CONFIGURE_ON=	--without-blas \
			--without-lapack
RBLAS_CONFIGURE_OFF=	--with-blas="-L${LOCALBASE}/lib ${BLASLIB}" \
			--with-lapack="${LAPACKLIB}"

TCLTK_IMPLIES=		X11
TCLTK_USES=		tcl tk:84+
TCLTK_CONFIGURE_WITH=	tcltk

THREADS_CONFIGURE_ON=	--enable-threads=posix
THREADS_CONFIGURE_OFF=	--disable-threads

TIFF_IMPLIES=		X11
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CONFIGURE_WITH=	libtiff

X11_CONFIGURE_WITH=	x
X11_USE=		xorg=ice,sm,x11,xext,xmu,xscrnsaver,xt

R_SOVERSION=		1
RBLAS_SOVERSION=	2
RLAPACK_SOVERSION=	4

PLIST_SUB=		R_SOVERSION="${R_SOVERSION}" \
			RBLAS_SOVERSION="${RBLAS_SOVERSION}" \
			RLAPACK_SOVERSION="${RLAPACK_SOVERSION}"

.include "compiler.mk"
.include <bsd.port.options.mk>

.if ${OSVERSION} > 1000052 && \
(${ARCH} == amd64 || ${ARCH} == i386 || ${ARCH} == ia64 || ${ARCH} == pc98 || \
${ARCH} == sparc64)
.for i in coshl erfcl erfl lgammal powl sinhl tanhl tgammal
CFLAGS+=		-fno-builtin-${i}
LDFLAGS+=		-fno-builtin-${i}
.endfor
.endif

post-patch:
.if !${PORT_OPTIONS:MMISSING}
.if ${OSVERSION} < 1000016
	@${REINPLACE_CMD} -e \
's/# define EXP expl/# define EXP(x) (long double)expq((__float128)(x))/' \
		${WRKSRC}/src/nmath/pnchisq.c \
		${WRKSRC}/src/nmath/pgamma.c
	@${REINPLACE_CMD} -e \
's/# define LOG logl/# define LOG(x) (long double)logq((__float128)(x))/' \
		${WRKSRC}/src/nmath/pnchisq.c \
		${WRKSRC}/src/nmath/pgamma.c
.endif
.if ${OSVERSION} < 1000034
	@${REINPLACE_CMD} -Ee 's/(log)(1p)?l\(/(long double)\1\2q((__float128)/'\
		${WRKSRC}/src/nmath/dnbeta.c \
		${WRKSRC}/src/nmath/pnbeta.c
.endif
	@${REINPLACE_CMD} -Ee \
's/powl\((.*)(long double)/(long double)powq((__float128)\1__float128/' \
		${WRKSRC}/src/main/format.c
.else # !PORT_OPTIONS:MMISSING
.if ${OSVERSION} > 1000052 && \
(${ARCH} == amd64 || ${ARCH} == i386 || ${ARCH} == ia64 || ${ARCH} == pc98 || \
${ARCH} == sparc64)
	@${REINPLACE_CMD} -e '\|^FLIBS="$$ac_cv_f77_libs"|s|"|&${LIBM} |' \
		${WRKSRC}/configure
.endif
	@${REINPLACE_CMD} -e \
'\|#[[:blank:]]*include[[:blank:]]*<complex.h>|{x;s|^.*$$|#include "missing_complex.h"|;H;x;}' \
		${WRKSRC}/src/main/complex.c
.endif # !PORT_OPTIONS:MMISSING
	@${REINPLACE_CMD} -e \
'\|#[[:blank:]]*include[[:blank:]]*<math.h>|{x;s|^.*$$|#include ${LIBMH}|;H;x;}'\
		${WRKSRC}/src/nmath/nmath.h \
		${WRKSRC}/src/include/Rmath.h0.in
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g'\
		${WRKSRC}/src/nmath/standalone/Makefile.in \
		${WRKSRC}/src/unix/Makefile.in
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|g" \
		${WRKSRC}/configure \
		${WRKSRC}/src/library/profile/Rprofile.unix \
		${WRKSRC}/src/scripts/javareconf.in

.if !${PORT_OPTIONS:MMISSING}
pre-configure:
	@if [ ! -f ${_GCC_RUNTIME}/libquadmath.a ] ; then \
		IGNORE="\n\n\n%s\n\n\n" "libquadmath is not available for your\
		compiler and architecture: please enable the MISSING option."; \
	fi
.endif

post-install:
.for L in R Rblas Rlapack
	@if [ -d ${STAGEDIR}${PREFIX}/lib/R/lib ] ; then \
	cd ${STAGEDIR}${PREFIX}/lib/R/lib; if [ -f lib${L}.so ] ; then \
	${LN} -sf lib${L}.so lib${L}.so.${${L:tu}_SOVERSION} ; fi; fi
.endfor

.include <bsd.port.mk>
