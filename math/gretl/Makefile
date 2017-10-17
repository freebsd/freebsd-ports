# Created by: ijliao
# $FreeBSD$

PORTNAME=	gretl
PORTVERSION=	1.9.13
PORTREVISION=	11
CATEGORIES=	math finance
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Regression, Econometrics, and Time-series Library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfftw3.so:math/fftw3 \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		fortran gmake localbase libtool ncurses pathfix pkgconfig \
		readline tar:bzip2

ALL_TARGET=		# empty
CONFIGURE_ARGS=	--enable-static --enable-shared --with-gmake \
			--disable-xdg-utils
CONFIGURE_ENV=	ac_cv_lib_dl_dlopen="" \
		LAPACK_LIBS="${LAPACK} ${BLAS}"

OPTIONS_DEFINE=	ATLAS GUI NLS ODBC OPENMP R UNZIP
OPTIONS_DEFAULT=	GUI OPENMP UNZIP
OPTIONS_SUB=	yes

ATLAS_DESC=		Use ATLAS for BLAS and LAPACK
ATLAS_LIB_DEPENDS=	libatlas.so:math/atlas
ATLAS_LIB_DEPENDS_OFF=	libblas.so:math/blas \
			liblapack.so:math/lapack
ATLAS_VARS=		BLAS=-lf77blas LAPACK="-lalapack -lcblas"
ATLAS_VARS_OFF=		BLAS=-lblas LAPACK=-llapack

GUI_DESC=		Graphical user interface and plugins
GUI_CONFIGURE_ON=	--enable-gtk2=yes --enable-gui=yes
GUI_CONFIGURE_OFF=	--enable-gui=no --enable-xdg=no
GUI_VARS=		INSTALLS_ICONS=yes
GUI_USE=		GNOME=cairo,gtksourceview2
GUI_USE_OFF=		GNOME=glib20,libxml2
GUI_USES=		desktop-file-utils shared-mime-info
GUI_BUILD_DEPENDS=	gnuplot:math/gnuplot
GUI_LIB_DEPENDS=	libfreetype.so:print/freetype2 \
			libfontconfig.so:x11-fonts/fontconfig
GUI_RUN_DEPENDS=	gnuplot:math/gnuplot

NLS_CONFIGURE_ON=	--enable-nls=yes
NLS_CONFIGURE_OFF=	--enable-nls=no
NLS_USES=		gettext

ODBC_CONFIGURE_WITH=	odbc
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC

OPENMP_CONFIGURE_ON=	--enable-openmp

R_DESC=			libR support
R_CONFIGURE_WITH=	libR
R_LIB_DEPENDS=          ${CRAN_DEPENDS}

UNZIP_DESC=		UnZip compression support via libgsf
UNZIP_CONFIGURE_WITH=	gsf
UNZIP_USE=		GNOME=libgsf

.if !empty(MACHINE_CPU:Msse2)
CONFIGURE_ARGS+=	--enable-sse2=yes
.else
CONFIGURE_ARGS+=	--enable-sse2=no
.endif

post-patch:
	@${SED} -i '.orig' -E -e '/#include[[:blank:]]+<sys\/socket\.h>/\
		{x; s/.*/#include <netinet\/in.h>/; H; x;}' \
		${WRKSRC}/configure \
		${WRKSRC}/plugin/mailer.c
	@${REINPLACE_CMD} -e 's| DOMAIN| CEPHES_DOMAIN|g' \
		${WRKSRC}/cephes/iv.c

regression-test test check: build
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_ARGS} check

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gretl-gtk2/*.so

.include <bsd.port.mk>
