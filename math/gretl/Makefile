# Created by: ijliao
# $FreeBSD$

PORTNAME=	gretl
PORTVERSION=	1.9.12
PORTREVISION=	1
CATEGORIES=	math finance
MASTER_SITES=	SF

MAINTAINER=	bf@FreeBSD.org
COMMENT=	GNU Regression, Econometrics, and Time-series Library

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		fftw3:${PORTSDIR}/math/fftw3

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_FORTRAN=	yes
USE_LDCONFIG=	yes
USES=		gmake pathfix pkgconfig
WANT_GNOME=	yes

ALL_TARGET=		# empty
CONFIGURE_ARGS =	--enable-static --enable-shared --with-gmake \
			--disable-xdg-utils
CONFIGURE_ENV=		ac_cv_lib_dl_dlopen=""
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ENV=		LAPACK_LIBS="${LAPACK} ${BLAS}"

MAN1=			gretl.1

OPTIONS_DEFINE =	ATLAS GUI ODBC OPENMP R

ATLAS_DESC =		Use ATLAS for BLAS and LAPACK
GUI_DESC=		Graphical user interface and plugins
R_DESC=			libR support

OPTIONS_DEFAULT=	GUI OPENMP

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MATLAS}
LIB_DEPENDS+=	atlas:${PORTSDIR}/math/atlas
BLAS=		-lf77blas
LAPACK=		-lalapack -lcblas
.else
LIB_DEPENDS+=	blas:${PORTSDIR}/math/blas \
		lapack:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.endif

.if ${PORT_OPTIONS:MGUI}
CONFIGURE_ARGS+=	--enable-gui=yes
INSTALLS_ICONS=		yes
USE_GNOME=		gtksourceview2
USES+=			desktop-file-utils shared-mime-info
BUILD_DEPENDS+=		gnuplot:${PORTSDIR}/math/gnuplot
RUN_DEPENDS+=		gnuplot:${PORTSDIR}/math/gnuplot
PLIST_SUB+=		GUI=""
.else
USE_GNOME=		glib20 libxml2
CONFIGURE_ARGS+=	--enable-gui=no --enable-xdg=no
PLIST_SUB+=		GUI="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--enable-nls=yes
USES+=		gettext
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--enable-nls=no
PLIST_SUB+=		NLS="@comment "
.endif

.if ${PORT_OPTIONS:MODBC}
CONFIGURE_ARGS+=	--with-odbc
LIB_DEPENDS+=		odbc:${PORTSDIR}/databases/unixODBC
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
LIB_DEPENDS+=		R:${PORTSDIR}/math/R
.else
CONFIGURE_ARGS+=	--without-libR
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
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${_MAKE_JOBS} \
		${MAKE_ARGS} check

.include <bsd.port.mk>
