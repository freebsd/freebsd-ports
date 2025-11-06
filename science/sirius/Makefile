PORTNAME=	sirius
DISTVERSIONPREFIX=	v
DISTVERSION=	7.9.0
CATEGORIES=	science
PKGNAMESUFFIX=	-quantum-chemistry # other software also has the name "sirius"

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Domain specific library for electronic structure calculations
WWW=		https://github.com/electronic-structure/SIRIUS/

LICENSE=	BSD3CLAUSE
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
USE_GITHUB=	yes
GH_ACCOUNT=	electronic-structure
GH_PROJECT=	SIRIUS
USE_LDCONFIG=	yes

CMAKE_OFF=	SIRIUS_USE_MEMORY_POOL # depends on umpire - not yet ported

OPTIONS_DEFAULT=	MPICH # NLCGLIB
OPTIONS_DEFINE=		NLCGLIB
OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	MPICH OPENMPI

NLCGLIB_DESC=		Enable nlcglib

MPICH_USES=		mpi:mpich
NLCGLIB_LIB_DEPENDS=	libnlcglib.so:science/nlcglib \
			libkokkoscore.so:devel/kokkos
NLCGLIB_CMAKE_BOOL=	USE_NLCGLIB

OPENMPI_USES=		mpi:openmpi

# pre-7.4.0: many tests fail, see https://github.com/electronic-structure/SIRIUS/issues/760
# 7.6.0: several tests fail: Can't divide 1 ranks into groups of size 4
# 7.7.0: tests fail to compile, see https://github.com/electronic-structure/SIRIUS/issues/1070

.include <bsd.port.mk>
