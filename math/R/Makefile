# Created by: Maurice Castro <maurice@serc.rmit.edu.au>
# $FreeBSD$

PORTNAME?=		R
PORTVERSION=		3.3.1
PORTREVISION=		3
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

CONFIGURE_ARGS=		--disable-java \
			--with-readline \
			rdocdir=${DOCSDIR}
GNU_CONFIGURE=		yes
INSTALL_TARGET=		install-strip
ONLY_FOR_ARCHS=		i386 amd64
USES=			fortran iconv libtool localbase objc:compiler perl5 \
			readline
USE_PERL5=		build

OPTIONS_DEFINE=		DOCS ICU INFO LDOUBLE LETTER LIBR MEMPROF NLS RPROF X11
OPTIONS_GROUP=		NEEDGCC NEEDX11
OPTIONS_GROUP_NEEDGCC=	LTO OPENMP
OPTIONS_GROUP_NEEDX11=	GHOSTSCRIPT JPEG CAIROPANGO PDF PNG TCLTK TIFF
OPTIONS_SINGLE=		BLAS
OPTIONS_SINGLE_BLAS=	ATLAS OPENBLAS NETLIB RBLAS

OPTIONS_SUB=		YES

ATLAS_DESC=		ATLAS BLAS implementation
GHOSTSCRIPT_DESC=	Graphics device for bitmap files via Ghostscript
CAIROPANGO_DESC=	Cairo graphics device and Pango multi-language text
INFO_DESC=		GNU info manuals
JPEG_DESC=		JPEG graphics device
LDOUBLE_DESC=		Long double data type
LETTER_DESC=		US letter paper
LIBR_DESC=		Shared R library
LTO_DESC=		Use Link Time Optimization
MEMPROF_DESC=		Memory profiling via Rprofmem() and tracemem()
NEEDGCC_DESC=		Require GCC
NEEDX11_DESC=		Require X11
NETLIB_DESC=		Netlib BLAS implementation
OPENBLAS_DESC=		OpenBLAS BLAS implementation
PDF_DESC=		PDF manuals (requires TeX)
PNG_DESC=		PNG graphics device
RBLAS_DESC=		Use R-bundled BLAS implementation
RPROF_DESC=		R profiling via Rprof()
X11_DESC=		X11 graphics device

OPTIONS_DEFAULT=	CAIROPANGO GHOSTSCRIPT ICU INFO JPEG LDOUBLE LIBR PNG \
			RBLAS RPROF TCLTK TIFF X11

ATLAS_USES=		blaslapack:atlas
ALTAS_CONFIGURE_ON=	--disable-BLAS-shlib
ATLAS_VARS=		MANUAL_PACKAGE_BUILD=\
"Choose a BLAS option other than ATLAS for package building."
CAIROPANGO_IMPLIES=	X11
CAIROPANGO_CONFIGURE_WITH=cairo
CAIROPANGO_USES=	gettext jpeg pkgconfig
CAIROPANGO_USE=		gnome=pango,cairo
DOCS_BUILD_DEPENDS=	texi2any:print/texinfo
GHOSTSCRIPT_IMPLIES=	X11
GHOSTSCRIPT_USES=	ghostscript
ICU_CONFIGURE_WITH=	ICU
ICU_LIB_DEPENDS=	libicui18n.so:devel/icu
INFO_IMPLIES=		DOCS
INFO_INSTALL_TARGET=	install-info
INFO_INFO=		R-FAQ R-admin R-data R-exts R-ints R-intro R-lang
JPEG_IMPLIES=		X11
JPEG_CONFIGURE_WITH=	jpeglib
JPEG_CONFIGURE_ENV=	r_cv_header_jpeglib_h=yes
JPEG_USES=		jpeg
LDOUBLE_CONFIGURE_ENABLE=long-double
LETTER_CONFIGURE_ENV=	R_PAPERSIZE=letter
LIBR_CONFIGURE_ENABLE=	R-shlib
LTO_CONFIGURE_ENABLE=	lto
LTO_USE=		gcc=yes
MEMPROF_CONFIGURE_ENABLE=memory-profiling
NETLIB_USES=		blaslapack:netlib
NETLIB_CONFIGURE_ON=	--disable-BLAS-shlib
NLS_CONFIGURE_OFF=	--disable-nls
NLS_USES=		gettext
OPENBLAS_USES=		blaslapack:openblas
OPENBLAS_CONFIGURE_ON=	--disable-BLAS-shlib
OPENMP_CONFIGURE_ENABLE=openmp
OPENMP_USE=		compiler:openmp
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
			--without-lapack \
			--enable-BLAS-shlib
RBLAS_CONFIGURE_OFF=	--with-blas="-L${LOCALBASE}/lib ${BLASLIB}" \
			--with-lapack="${LAPACKLIB}"
RPROF_CONFIGURE_ENABLE=	R-profiling
TCLTK_IMPLIES=		X11
TCLTK_USES=		tcl tk:84+
TCLTK_CONFIGURE_WITH=	tcltk
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

.include <bsd.port.options.mk>
.include "compiler.mk"

# OPT_USE= ldconfig=${PREFIX}/lib/R/lib is broken.
# It adds /lib/R/lib (without PREFIX) to ${PREFIX}/libdata/R.
.if ${PORT_OPTIONS:MLIBR} || ${PORT_OPTIONS:MRBLAS}
USE_LDCONFIG=		${PREFIX}/lib/R/lib
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g'\
		${WRKSRC}/src/nmath/standalone/Makefile.in \
		${WRKSRC}/src/unix/Makefile.in
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|g" \
		${WRKSRC}/configure

post-install:
.for L in R Rblas Rlapack
	@if [ -d ${STAGEDIR}${PREFIX}/lib/R/lib ] ; then \
	cd ${STAGEDIR}${PREFIX}/lib/R/lib; if [ -f lib${L}.so ] ; then \
	${LN} -sf lib${L}.so lib${L}.so.${${L:tu}_SOVERSION} ; fi; fi
.endfor

.include <bsd.port.mk>
