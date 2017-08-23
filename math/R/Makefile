# Created by: Maurice Castro <maurice@serc.rmit.edu.au>
# $FreeBSD$

PORTNAME=		R
PORTVERSION=		3.4.1
PORTREVISION=		5
CATEGORIES=		math lang
MASTER_SITES=		CRAN/src/base/R-${PORTVERSION:C|\..*||}

MAINTAINER=		jrm@FreeBSD.org
COMMENT=		Language for statistical computing and graphics

LICENSE=		GPLv2

LIB_DEPENDS=		libcurl.so:ftp/curl \
			libpcre.so:devel/pcre
BUILD_DEPENDS=		texi2any:print/texinfo
RUN_DEPENDS=		gmake:devel/gmake

CONFIGURE_ARGS=		--disable-java \
			--with-readline \
			rdocdir=${DOCSDIR}
GNU_CONFIGURE=		yes
INSTALL_TARGET=		install-strip
ONLY_FOR_ARCHS=		aarch64 amd64 i386
USES=			gmake iconv libtool localbase \
			pathfix perl5 readline:port

USE_PERL5=		build
USE_LDCONFIG=		${PREFIX}/lib/R/lib

OPTIONS_DEFINE=		ICU INFO LDOUBLE LETTER LIBR MEMPROF NLS RPROF X11
OPTIONS_GROUP=		NEEDGCC NEEDX11
OPTIONS_GROUP_NEEDGCC=	LTO OPENMP
OPTIONS_GROUP_NEEDX11=	GHOSTSCRIPT JPEG CAIROPANGO PNG TCLTK TEXDOCS TIFF
OPTIONS_SINGLE=		BLAS FORTRAN
OPTIONS_SINGLE_BLAS=	ATLAS OPENBLAS NETLIB RBLAS
OPTIONS_SINGLE_FORTRAN=	${OPTIONS_SINGLE_FORTRAN_${MACHINE_ARCH}}
OPTIONS_SINGLE_FORTRAN_i386=	GFORTRAN
OPTIONS_SINGLE_FORTRAN_aarch64=	GFORTRAN
OPTIONS_SINGLE_FORTRAN_amd64=	GFORTRAN FLANG

OPTIONS_SUB=		YES

ATLAS_DESC=		ATLAS BLAS implementation
FLANG_DESC=		Experimental Fortran support via flang
GHOSTSCRIPT_DESC=	Graphics device for bitmap files via Ghostscript
CAIROPANGO_DESC=	Cairo graphics device and Pango multi-language text
GFORTRAN_DESC=		Fortran support via gfortran
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
PNG_DESC=		PNG graphics device
RBLAS_DESC=		Use R-bundled BLAS implementation
RPROF_DESC=		R profiling via Rprof()
TEXDOCS_DESC=		Build/Install TeX-dependent documentation files
X11_DESC=		X11 graphics device

OPTIONS_DEFAULT=	CAIROPANGO GFORTRAN GHOSTSCRIPT ICU INFO JPEG LDOUBLE \
			LIBR PNG RBLAS RPROF TCLTK TIFF X11

ATLAS_USES=		blaslapack:atlas
ATLAS_CONFIGURE_ON=	--disable-BLAS-shlib
ATLAS_VARS=		MANUAL_PACKAGE_BUILD=\
"Choose a BLAS option other than ATLAS for package building."
CAIROPANGO_IMPLIES=	X11
CAIROPANGO_CONFIGURE_WITH=cairo
CAIROPANGO_USES=	gettext jpeg pkgconfig
CAIROPANGO_USE=		GNOME=pango,cairo
FLANG_USE=		binutils
FLANG_PREVENTS=		ATLAS OPENBLAS NETLIB
FLANG_BUILD_DEPENDS=	flang:devel/flang
FLANG_RUN_DEPENDS=	flang:devel/flang
FLANG_VARS=		F77=flang FC=flang
FLANG_LDFLAGS=		-L${LOCALBASE}/flang/lib -lflang -lexecinfo
FLANG_CONFIGURE_ENV=	F77="${F77}" FC="${FC}" FFLAGS="${FFLAGS}"
FLANG_MAKE_ENV=		F77="${F77}" FC="${FC}" FFLAGS="${FFLAGS}"
GFORTRAN_USES=		fortran
GFORTRAN_RUN_DEPENDS=	wget:ftp/wget
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
LDOUBLE_CONFIGURE_ENABLE=long-double
LETTER_CONFIGURE_ENV=	R_PAPERSIZE=letter
LIBR_CONFIGURE_ENABLE=	R-shlib
LIBR_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-src_main_Makefile.in
LTO_CONFIGURE_ENABLE=	lto
LTO_CONFIGURE_ENV=	AR="${LOCALBASE}/bin/gcc-ar${GCC_DEFAULT:S/.//g}" \
			RANLIB="${LOCALBASE}/bin/gcc-ranlib${GCC_DEFAULT:S/.//g}"
LTO_PREVENTS=		FLANG
LTO_USE=		GCC=yes
LTO_VARS=		BINUTILS="ADDR2LINE AS CPPFILT GPROF LD NM OBJCOPY \
			OBJDUMP READELF SIZE STRINGS"
MEMPROF_CONFIGURE_ENABLE=memory-profiling
NETLIB_USES=		blaslapack:netlib
NETLIB_CONFIGURE_ON=	--disable-BLAS-shlib
NLS_CONFIGURE_OFF=	--disable-nls
NLS_USES=		gettext
OPENBLAS_USES=		blaslapack:openblas
OPENBLAS_CONFIGURE_ON=	--disable-BLAS-shlib
OPENMP_CONFIGURE_ENABLE=openmp
OPENMP_LIB_DEPENDS=	libomp.so:devel/openmp
OPENMP_USES=		compiler:openmp
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
TCLTK_USES=		tcl tk:84+
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

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|g" ${WRKSRC}/configure
	@${REINPLACE_CMD} "s|%%LIBVER%%|${LIBVER}|" \
		${WRKSRC}/src/main/Makefile.in \
		${WRKSRC}/src/extra/blas/Makefile.in \
		${WRKSRC}/src/modules/lapack/Makefile.in

.include <bsd.port.pre.mk>
.include "compiler.mk"
.include <bsd.port.post.mk>
