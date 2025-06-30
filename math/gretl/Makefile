PORTNAME=	gretl
PORTVERSION=	2024d
PORTREVISION=	2
CATEGORIES=	math finance
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSIONFULL}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GNU Regression, Econometrics, and Time-series Library
WWW=		https://gretl.sourceforge.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_13=	configure fails: checking for gnuplot >= 5.2 with cairo support... no

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfftw3.so:math/fftw3 \
		libgmp.so:math/gmp \
		libharfbuzz.so:print/harfbuzz \
		libjson-glib-1.0.so:devel/json-glib \
		libmpfr.so:math/mpfr

USES=		compiler:c11 fortran gmake gnome localbase libtool ncurses \
		pathfix pkgconfig readline shebangfix tar:xz
USE_WX=		3.0
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.sh

GNU_CONFIGURE=	yes

BINARY_ALIAS=	make=${GMAKE}
ALL_TARGET=	# empty
SSP_CFLAGS?=	-fstack-protector # XXX -strong crashes mklang on 12.0+ i386
CONFIGURE_ENV=	ac_cv_lib_dl_dlopen="" \
		LAPACK_LIBS="${LAPACK} ${BLAS}"

PLIST_SUB=	GTK_VER=${GTK_VER}

OPTIONS_DEFINE=		ADDONS ATLAS GUI MPI NLS ODBC OPENMP R UNZIP
OPTIONS_DEFAULT=	ADDONS GUI OPENMP UNZIP
OPTIONS_SUB=		yes

ADDONS_DESC=		Build gretl addons
ADDONS_CONFIGURE_ENABLE=	build-addons
ADDONS_USES=		tex
ADDONS_USE=			TEX=formats,dvipsk:build

ATLAS_DESC=		Use ATLAS for BLAS and LAPACK
ATLAS_LIB_DEPENDS=	libatlas.so:math/atlas
ATLAS_LIB_DEPENDS_OFF=	libblas.so:math/blas \
			liblapack.so:math/lapack
ATLAS_VARS=		BLAS=-lf77blas LAPACK="-lalapack -lcblas"
ATLAS_VARS_OFF=		BLAS=-lblas LAPACK=-llapack

GUI_DESC=		Graphical user interface and plugins
GUI_CONFIGURE_ON=	--enable-gui=yes
GUI_CONFIGURE_OFF=	--enable-gui=no --enable-xdg=no
GUI_USE=		GNOME=cairo,gtksourceview4,gdkpixbuf
GUI_USE_OFF=		GNOME=glib20,libxml2
GUI_VARS=		GTK_VER=3
GUI_VARS_OFF=		GTK_VER=2
GUI_USES=		desktop-file-utils shared-mime-info
GUI_BUILD_DEPENDS=	gnuplot:math/gnuplot
GUI_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig
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
OPENMP_USE=		GCC=yes

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

post-patch:
	@${SED} -i '.orig' -E -e '/#include[[:blank:]]+<sys\/socket\.h>/\
		{x; s/.*/#include <netinet\/in.h>/; H; x;}' \
		${WRKSRC}/configure \
		${WRKSRC}/plugin/mailer.c

regression-test test check: build
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_ARGS} check

post-install:
	# strip
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/gretlcli \
		${STAGEDIR}${PREFIX}/bin/gretl_x11 \
		${STAGEDIR}${PREFIX}/lib/libgretl-1.0.so.* \
		${STAGEDIR}${PREFIX}/lib/gretl-gtk3/*.so
	# rm doc
	@${RMDIR} ${STAGEDIR}${DATADIR}/doc

.include <bsd.port.mk>
