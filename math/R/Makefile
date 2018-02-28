# Created by: Maurice Castro <maurice@serc.rmit.edu.au>
# $FreeBSD$

PORTNAME=		R
DISTVERSION=		3.4.3
PORTREVISION=		2
CATEGORIES=		math lang
MASTER_SITES=		CRAN/src/base/R-${PORTVERSION:C|\..*||}

MAINTAINER=		jrm@FreeBSD.org
COMMENT=		Language for statistical computing and graphics

LICENSE=		GPLv2

BROKEN_FreeBSD_10_armv6=	Fails to build
ONLY_FOR_ARCHS=		aarch64 amd64 armv6 armv7 i386

LIB_DEPENDS=		libcurl.so:ftp/curl \
			libpcre.so:devel/pcre
BUILD_DEPENDS=		texi2any:print/texinfo
RUN_DEPENDS=		gmake:devel/gmake # R packages may require GNU make

# possible TODO
# - Use --with-recommended-packages=no by default
# - Add an option for recommended packages
# - Create ports for each of the recommended packages
# - Create a meta-port for the recommended packages

CONFIGURE_ARGS=		--disable-java \
			--enable-R-shlib \
			--with-readline \
			rdocdir=${DOCSDIR}
GNU_CONFIGURE=		yes
INSTALL_TARGET=		install-strip
USES=			gmake iconv libtool localbase \
			pathfix perl5 readline:port
USE_PERL5=		build
USE_LDCONFIG=		${PREFIX}/lib/R/lib

OPTIONS_DEFINE=		FLANG ICU INFO LDOUBLE LETTER MEMPROF NLS OPENMP RPROF \
			X11
OPTIONS_EXCLUDE_aarch64=	FLANG OPENMP
OPTIONS_EXCLUDE_armv6=	FLANG OPENMP
OPTIONS_EXCLUDE_armv7=	FLANG OPENMP
OPTIONS_EXCLUDE_i386=	FLANG
OPTIONS_GROUP=		NEEDX11
OPTIONS_GROUP_NEEDX11=	GHOSTSCRIPT JPEG CAIROPANGO PNG TCLTK TEXDOCS TIFF
OPTIONS_SINGLE=		BLAS
OPTIONS_SINGLE_BLAS=	ATLAS OPENBLAS NETLIB RBLAS

OPTIONS_SUB=		YES

ATLAS_DESC=		ATLAS BLAS implementation
FLANG_DESC=		Use flang instead of the default Fortran compiler
GHOSTSCRIPT_DESC=	Graphics device for bitmap files via Ghostscript
CAIROPANGO_DESC=	Cairo graphics device and Pango multi-language text
INFO_DESC=		GNU info manuals
JPEG_DESC=		JPEG graphics device
LDOUBLE_DESC=		Long double data type
LETTER_DESC=		US letter paper
MEMPROF_DESC=		Memory profiling via Rprofmem() and tracemem()
NEEDX11_DESC=		Require X11
NETLIB_DESC=		Netlib BLAS implementation
OPENBLAS_DESC=		OpenBLAS BLAS implementation
PNG_DESC=		PNG graphics device
RBLAS_DESC=		Use R-bundled BLAS implementation
RPROF_DESC=		R profiling via Rprof()
TEXDOCS_DESC=		Build/Install TeX-dependent documentation files
X11_DESC=		X11 graphics device

OPTIONS_DEFAULT=	CAIROPANGO GHOSTSCRIPT ICU INFO JPEG LDOUBLE OPENMP \
			PNG RBLAS RPROF TCLTK TIFF X11

ATLAS_USES=		blaslapack:atlas
ATLAS_CONFIGURE_ON=	--disable-BLAS-shlib
ATLAS_VARS=		MANUAL_PACKAGE_BUILD=\
"Choose a BLAS option other than ATLAS for package building."
CAIROPANGO_IMPLIES=	X11
CAIROPANGO_CONFIGURE_WITH=	cairo
CAIROPANGO_USES=	gettext jpeg pkgconfig
CAIROPANGO_USE=		GNOME=pango,cairo
FLANG_USES=		fortran:flang
FLANG_USES_OFF=		fortran
FLANG_PREVENTS=		ATLAS OPENBLAS NETLIB
GHOSTSCRIPT_IMPLIES=	X11
GHOSTSCRIPT_USES=	ghostscript
ICU_CONFIGURE_WITH=	ICU
ICU_LIB_DEPENDS=	libicui18n.so:devel/icu
INFO_INSTALL_TARGET=	install-info
INFO_INFO=		R-FAQ R-admin R-data R-exts R-ints R-intro R-lang
JPEG_IMPLIES=		X11
JPEG_CONFIGURE_WITH=	jpeglib
JPEG_CONFIGURE_ENV=	r_cv_header_jpeglib_h=yes
JPEG_USES=		jpeg
LDOUBLE_CONFIGURE_ENABLE=	long-double
LETTER_CONFIGURE_ENV=	R_PAPERSIZE=letter
MEMPROF_CONFIGURE_ENABLE=	memory-profiling
NETLIB_USES=		blaslapack:netlib
NETLIB_CONFIGURE_ON=	--disable-BLAS-shlib
NLS_CONFIGURE_OFF=	--disable-nls
NLS_USES=		gettext
OPENBLAS_USES=		blaslapack:openblas
OPENBLAS_CONFIGURE_ON=	--disable-BLAS-shlib
OPENMP_CONFIGURE_ENABLE=	openmp
PNG_IMPLIES=		X11
PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_WITH=	libpng
RBLAS_CONFIGURE_ON=	--without-blas \
			--without-lapack \
			--enable-BLAS-shlib
RBLAS_CONFIGURE_OFF=	--with-blas="-L${LOCALBASE}/lib ${BLASLIB}" \
			--with-lapack="${LAPACKLIB}"
RBLAS_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-src_extra_blas_Makefile.in \
			${PATCHDIR}/extra-patch-src_modules_lapack_Makefile.in
RPROF_CONFIGURE_ENABLE=	R-profiling
TCLTK_IMPLIES=		X11
TCLTK_USES=		tcl tk
TCLTK_CONFIGURE_WITH=	tcltk
.for i in KPSEWHICH MAKEINDEX PDFLATEX PDFTEX TEX TEXI2DVI
TEXDOCS_CONFIGURE_ENV_OFF+=	ac_cv_path_${i}=""
.endfor
TEXDOCS_INSTALL_TARGET=	install-pdf
TEXDOCS_USE=		tex=dvipsk:build,kpathsea:build,pdftex:build
TIFF_IMPLIES=		X11
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CONFIGURE_WITH=	libtiff
X11_CONFIGURE_WITH=	x
X11_USE=		xorg=ice,sm,x11,xext,xmu,xscrnsaver,xt

LIBVER=		${PORTVERSION:R}
PLIST_SUB=	LIBVER=${LIBVER}

.include <bsd.port.options.mk>
.include "compiler.mk"

# LLVM, which gets pulled in with FLANG, provides libomp.  So, only depend on
# devel/openmp, when GFORTRAN and OPENMP are on.
.if ! ${PORT_OPTIONS:MFLANG} && ${PORT_OPTIONS:MOPENMP}
LIB_DEPENDS+=	libomp.so:devel/openmp
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|g" ${WRKSRC}/configure
	@${REINPLACE_CMD} "s|%%LIBVER%%|${LIBVER}|" \
		${WRKSRC}/src/main/Makefile.in \
		${WRKSRC}/src/extra/blas/Makefile.in \
		${WRKSRC}/src/modules/lapack/Makefile.in

post-install-RBLAS-on:
	@${REINPLACE_CMD} -e "s| -lR| -lR -lRblas|" \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/libR.pc

post-install-RBLAS-off:
	@${REINPLACE_CMD} -e "s| -lR| -lR ${BLASLIB}|" \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/libR.pc

.include <bsd.port.mk>
