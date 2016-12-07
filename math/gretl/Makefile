# Created by: ijliao
# $FreeBSD$

PORTNAME=	gretl
PORTVERSION=	1.9.13
PORTREVISION=	7
CATEGORIES=	math finance
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Regression, Econometrics, and Time-series Library

LICENSE=	GPLv3

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfftw3.so:math/fftw3

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		fortran gmake libtool pathfix pkgconfig tar:bzip2
WANT_GNOME=	yes

ALL_TARGET=		# empty
CONFIGURE_ARGS=	--enable-static --enable-shared --with-gmake \
			--disable-xdg-utils
CONFIGURE_ENV=		ac_cv_lib_dl_dlopen=""
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ENV=		LAPACK_LIBS="${LAPACK} ${BLAS}"

OPTIONS_DEFINE=	ATLAS GUI ODBC OPENMP R UNZIP

ATLAS_DESC=		Use ATLAS for BLAS and LAPACK
GUI_DESC=		Graphical user interface and plugins
R_DESC=			libR support
UNZIP_DESC=		UnZip compression support via libgsf

OPTIONS_DEFAULT=	GUI OPENMP UNZIP

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MATLAS}
LIB_DEPENDS+=	libatlas.so:math/atlas
BLAS=		-lf77blas
LAPACK=		-lalapack -lcblas
.else
LIB_DEPENDS+=	libblas.so:math/blas \
		liblapack.so:math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.endif

.if ${PORT_OPTIONS:MGUI}
CONFIGURE_ARGS+=	--enable-gtk2=yes --enable-gui=yes
INSTALLS_ICONS=		yes
USE_GNOME=		gtksourceview2
USES+=			desktop-file-utils shared-mime-info
BUILD_DEPENDS+=		gnuplot:math/gnuplot
RUN_DEPENDS+=		gnuplot:math/gnuplot
PLIST_SUB+=		GUI=""
.else
USE_GNOME=		glib20 libxml2
CONFIGURE_ARGS+=	--enable-gui=no --enable-xdg=no
PLIST_SUB+=		GUI="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--enable-nls=yes
USES+=			gettext
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--enable-nls=no
PLIST_SUB+=		NLS="@comment "
.endif

.if ${PORT_OPTIONS:MODBC}
CONFIGURE_ARGS+=	--with-odbc
LIB_DEPENDS+=		libodbc.so:databases/unixODBC
PLIST_SUB+=		ODBC=""
.else
CONFIGURE_ARGS+=	--without-odbc
PLIST_SUB+=		ODBC="@comment "
.endif

.if ${PORT_OPTIONS:MOPENMP}
CONFIGURE_ARGS+=	--enable-openmp
.endif

.if ${PORT_OPTIONS:MR}
CONFIGURE_ARGS+=	--with-libR
LIB_DEPENDS+=		libR.so:math/R
.else
CONFIGURE_ARGS+=	--without-libR
.endif

.if ${PORT_OPTIONS:MUNZIP}
CONFIGURE_ARGS+=	--with-gsf
USE_GNOME+=		libgsf
PLIST_SUB+=		NO_UNZIP="@comment "
.else
CONFIGURE_ARGS+=	--without-gsf
PLIST_SUB+=		NO_UNZIP=""
.endif

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

.include <bsd.port.mk>
