PORTNAME=	R
DISTVERSION=	4.5.1
PORTREVISION=	1
CATEGORIES=	math lang
MASTER_SITES=	CRAN/src/base/R-${PORTVERSION:C|\..*||}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Language for statistical computing and graphics
WWW=		https://www.R-project.org/

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 powerpc powerpc64 powerpc64le

BUILD_DEPENDS=	texi2any:print/texinfo
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libdeflate.so:archivers/libdeflate \
		libpcre2-8.so:devel/pcre2 \
		libzstd.so:archivers/zstd
# R packages may require GNU make or cmake to build
RUN_DEPENDS=	cmake:devel/cmake-core \
		gmake:devel/gmake

# possible TODO
# - Use --with-recommended-packages=no by default
# - Add an option for recommended packages
# - Create ports for each of the recommended packages
# - Create a meta-port for the recommended packages

USES=		compiler:c++23-lang cpe fortran gmake iconv libtool localbase \
		pathfix perl5 readline
CPE_VENDOR=	r-project
USE_LDCONFIG=	${PREFIX}/lib/R/lib
USE_PERL5=	build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-java \
		--enable-R-shlib \
		--with-readline \
		rdocdir=${DOCSDIR}
INSTALL_TARGET=	install-strip
PLIST_SUB=	FULLVER=${DISTVERSION} \
		MAJORVER=${_MAJORVER}

OPTIONS_DEFINE=		ICU INFO LDOUBLE LETTER MEMPROF NLS OPENMP RPROF X11
OPTIONS_DEFAULT=	CAIROPANGO GHOSTSCRIPT ICU INFO JPEG LDOUBLE OPENMP PNG \
			RBLAS RPROF TCLTK TIFF X11
OPTIONS_GROUP=		NEEDX11
OPTIONS_GROUP_NEEDX11=	CAIROPANGO GHOSTSCRIPT JPEG PNG TCLTK TEXDOCS TIFF
OPTIONS_SINGLE=		BLAS
OPTIONS_SINGLE_BLAS=	ATLAS NETLIB OPENBLAS RBLAS

OPTIONS_SUB=	YES

CAIROPANGO_DESC=	Cairo graphics device and Pango multi-language text
GHOSTSCRIPT_DESC=	Graphics device for bitmap files via Ghostscript
JPEG_DESC=		JPEG graphics device
LDOUBLE_DESC=		Long double data type
LETTER_DESC=		US letter paper
MEMPROF_DESC=		Memory profiling via Rprofmem() and tracemem()
NEEDX11_DESC=		Require X11
NETLIB_DESC=		Netlib BLAS implementation
PNG_DESC=		PNG graphics device
RBLAS_DESC=		Use R-bundled BLAS implementation
RPROF_DESC=		R profiling via Rprof()
TEXDOCS_DESC=		Build/Install TeX-dependent documentation files
X11_DESC=		X11 graphics device

ATLAS_USES=			blaslapack:atlas
ATLAS_CONFIGURE_ON=		--disable-BLAS-shlib
CAIROPANGO_IMPLIES=		X11
CAIROPANGO_LIB_DEPENDS=		libharfbuzz.so:print/harfbuzz
CAIROPANGO_USES=		gettext gnome jpeg pkgconfig
CAIROPANGO_USE=			GNOME=cairo,pango
CAIROPANGO_CONFIGURE_WITH=	cairo
GHOSTSCRIPT_IMPLIES=		X11
GHOSTSCRIPT_USES=		ghostscript
ICU_LIB_DEPENDS=		libicui18n.so:devel/icu
ICU_CONFIGURE_WITH=		ICU
INFO_INSTALL_TARGET=		install-info
INFO_INFO=			R-admin R-data R-exts R-FAQ R-intro R-ints \
				R-lang
JPEG_IMPLIES=			X11
JPEG_USES=			jpeg pkgconfig
JPEG_CONFIGURE_WITH=		jpeglib
JPEG_CONFIGURE_ENV=		r_cv_header_jpeglib_h=yes
LDOUBLE_CONFIGURE_ENABLE=	long-double
LETTER_CONFIGURE_ENV=		R_PAPERSIZE=letter
MEMPROF_CONFIGURE_ENABLE=	memory-profiling
NETLIB_USES=			blaslapack:netlib
NETLIB_CONFIGURE_ON=		--disable-BLAS-shlib
NLS_USES=			gettext
NLS_CONFIGURE_OFF=		--disable-nls
OPENBLAS_USES=			blaslapack:openblas
OPENBLAS_CONFIGURE_ON=		--disable-BLAS-shlib
OPENMP_CONFIGURE_ENABLE=	openmp
PNG_IMPLIES=			X11
PNG_LIB_DEPENDS=		libpng16.so:graphics/png
PNG_CONFIGURE_WITH=		libpng
RBLAS_CONFIGURE_ON=		--enable-BLAS-shlib \
				--without-blas \
				--without-lapack
RBLAS_CONFIGURE_OFF=		--with-blas="-L${LOCALBASE}/lib ${BLASLIB}" \
				--with-lapack="${LAPACKLIB}"
RBLAS_EXTRA_PATCHES=		${PATCHDIR}/extra-patch-src_extra_blas_Makefile.in \
				${PATCHDIR}/extra-patch-src_modules_lapack_Makefile.in
RPROF_CONFIGURE_ENABLE=		R-profiling
TCLTK_IMPLIES=			X11
TCLTK_USES=			tcl tk
TCLTK_CONFIGURE_WITH=		tcl_config=${TCL_LIBDIR}/tclConfig.sh tcltk \
				tk_config=${TK_LIBDIR}/tkConfig.sh
TEXDOCS_USES=			tex
TEXDOCS_USE=			TEX=dvipsk:build,kpathsea:build,pdftex:build
.for i in KPSEWHICH MAKEINDEX PDFLATEX PDFTEX TEX TEXI2DVI
TEXDOCS_CONFIGURE_ENV_OFF+=	ac_cv_path_${i}=""
.endfor
TEXDOCS_INSTALL_TARGET=		install-pdf
TIFF_IMPLIES=			X11
TIFF_LIB_DEPENDS=		libtiff.so:graphics/tiff
TIFF_CONFIGURE_WITH=		libtiff
X11_USES=			xorg
X11_USE=			XORG=ice,sm,x11,xext,xmu,xscrnsaver,xt
X11_CONFIGURE_WITH=		x

_MAJORVER=	${DISTVERSION:R:R}

post-patch:
	@${REINPLACE_CMD} \
		-e "s|%%FULLVER%%|${DISTVERSION}|" \
		-e "s|%%MAJORVER%%|${_MAJORVER}|" \
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
