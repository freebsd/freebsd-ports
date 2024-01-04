PORTNAME=	sirius
DISTVERSIONPREFIX=	v
DISTVERSION=	7.5.0
CATEGORIES=	science
PKGNAMESUFFIX=	-quantum-chemistry # other software also has the name "sirius"

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Domain specific library for electronic structure calculations
WWW=		https://github.com/electronic-structure/SIRIUS

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcosta.so:math/costa \
		libgsl.so:math/gsl \
		libhdf5.so:science/hdf5 \
		libopenblas.so:math/openblas \
		libscalapack.so:math/scalapack \
		libspfft.so:math/spfft \
		libspla.so:math/spla \
		libsymspg.so:science/spglib \
		libxc.so:science/libxc

USES=		cmake:testing compiler:c++14-lang eigen:3,test fortran pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	electronic-structure
GH_PROJECT=	SIRIUS

CMAKE_OFF=	SIRIUS_USE_MEMORY_POOL # depends on umpire - not yet ported

OPTIONS_DEFINE=		NLCGLIB
OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	MPICH OPENMPI
OPTIONS_DEFAULT=	MPICH # NLCGLIB

NLCGLIB_DESC=		Enable nlcglib
NLCGLIB_CMAKE_BOOL=	USE_NLCGLIB
NLCGLIB_LIB_DEPENDS=	libnlcglib.so:science/nlcglib \
			libkokkoscore.so:devel/kokkos
NLCGLIB_BROKEN=		build breaks, see https://github.com/electronic-structure/SIRIUS/issues/759

MPICH_USES=		mpi:mpich

OPENMPI_USES=		mpi:openmpi

# many tests fail, see https://github.com/electronic-structure/SIRIUS/issues/760
# 7.5.0: tests fail to build, see https://github.com/electronic-structure/SIRIUS/issues/947

.include <bsd.port.mk>
