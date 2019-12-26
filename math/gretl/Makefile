# Created by: ijliao
# $FreeBSD$

PORTNAME=	gretl
DISTVERSION=	2019d
CATEGORIES=	math finance
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSIONFULL}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GNU Regression, Econometrics, and Time-series Library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfftw3.so:math/fftw3 \
		libgmp.so:math/gmp \
		libjson-glib-1.0.so:devel/json-glib \
		libmpfr.so:math/mpfr

USES=		fortran gmake gnome localbase libtool ncurses pathfix pkgconfig \
		readline tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

BINARY_ALIAS=	make=${GMAKE}
ALL_TARGET=	# empty
SSP_CFLAGS?=	-fstack-protector # XXX -strong crashes mklang on 12.0+ i386
CONFIGURE_ENV=	ac_cv_lib_dl_dlopen="" \
		LAPACK_LIBS="${LAPACK} ${BLAS}"

OPTIONS_DEFINE=		ADDONS ATLAS GUI MPI NLS ODBC OPENMP R UNZIP
OPTIONS_DEFAULT=	ADDONS GUI OPENMP UNZIP
OPTIONS_SUB=		yes

ADDONS_DESC=		Build gretl addons
ADDONS_CONFIGURE_ENABLE=	build-addons
ADDONS_VARS=		USE_TEX="formats dvipsk:build"

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

MPI_CONFIGURE_WITH=	mpi
MPI_CONFIGURE_ENV=	MPICC=${LOCALBASE}/bin/mpicc
MPI_CONFIGURE_ON=	--with-mpi-include=${LOCALBASE}/include/mpi.h --with-mpi-lib=${LOCALBASE}/lib/libmpi.so
MPI_LIB_DEPENDS=	libmpi.so:net/mpich
MPI_BROKEN=		checking mpi.h usability... no # need to investigate

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

ODBC_CONFIGURE_WITH=	odbc
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC

OPENMP_CONFIGURE_ENABLE=	openmp
OPENMP_USES=		compiler:openmp

R_DESC=			libR support
R_CONFIGURE_WITH=	libR
R_BROKEN=		Doesn't link to R libraries

UNZIP_DESC=		UnZip compression support via libgsf
UNZIP_CONFIGURE_WITH=	gsf
UNZIP_USE=		GNOME=libgsf

.if !empty(MACHINE_CPU:Msse2)
CONFIGURE_ARGS+=	--enable-sse2=yes
.else
CONFIGURE_ARGS+=	--enable-sse2=no
.endif

.include <bsd.port.pre.mk>

# XXX Drop after FreeBSD 12.0 EOL
.if !exists(/usr/include/omp.h)
LIB_DEPENDS+=	libomp.so:devel/openmp
.endif

post-patch:
	@${SED} -i '.orig' -E -e '/#include[[:blank:]]+<sys\/socket\.h>/\
		{x; s/.*/#include <netinet\/in.h>/; H; x;}' \
		${WRKSRC}/configure \
		${WRKSRC}/plugin/mailer.c
	@${REINPLACE_CMD} -e 's| DOMAIN| CEPHES_DOMAIN|g' \
		${WRKSRC}/cephes/iv.c

regression-test test check: build
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_ARGS} check

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gretl-gtk2/*.so
	@${RMDIR} ${STAGEDIR}${DATADIR}/doc

.include <bsd.port.post.mk>
