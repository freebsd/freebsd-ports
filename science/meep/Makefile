# Created by: Stas Timokhin <devel@stasyan.com>
# $FreeBSD$

PORTNAME=	meep
PORTVERSION=	1.2.1
PORTREVISION=	16
CATEGORIES=	science
MASTER_SITES=	http://ab-initio.mit.edu/meep/

MAINTAINER=	devel@stasyan.com
COMMENT=	FDTD simulation software to model electromagnetic systems

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	harminv:science/harminv \
		gsed:textproc/gsed
LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libblas.so:math/blas \
		libguile-2.0.so:lang/guile2 \
		libctl.so:science/libctl \
		libgc-threaded.so:devel/boehm-gc-threaded \
		libgsl.so:math/gsl \
		libhdf5.so:science/hdf5 \
		liblapack.so:math/lapack
RUN_DEPENDS=	harminv:science/harminv

USES=		fortran gettext gmake iconv libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_GCC=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ARGS+=	CC="${CC}" CXX="${CXX}"

OPTIONS_RADIO=		MPI
OPTIONS_RADIO_MPI=	OPENMPI MPICH2
OPTIONS_DEFAULT=	${OPTIONS_DEFAULT_${OPSYS}}
OPTIONS_DEFAULT_FreeBSD=	MPICH2
OPENMPI_DESC=		MPI support (with OpenMPI)

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MMPICH2} || ${PORT_OPTIONS:MOPENMPI}
CONFIGURE_ARGS+=	--with-mpi
PLIST_SUB+=		MPI="" NOMPI="@comment "
.else
CONFIGURE_ARGS+=	--without-mpi
PLIST_SUB+=		MPI="@comment " NOMPI=""
.endif

.if ${PORT_OPTIONS:MMPICH2}
LIB_DEPENDS+=	libmpich.so:net/mpich2
CONFIGURE_ENV+=	MPICXX=${LOCALBASE}/bin/mpicc
CFLAGS+=	-I${LOCALBASE}/include
.endif

.if ${PORT_OPTIONS:MOPENMPI}
BUILD_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpiCC:net/openmpi
RUN_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpirun:net/openmpi
CONFIGURE_ENV+=	MPICXX=${LOCALBASE}/mpi/openmpi/bin/mpiCC
CFLAGS+=	-I${LOCALBASE}/mpi/openmpi/include
.endif

.include <bsd.port.post.mk>
