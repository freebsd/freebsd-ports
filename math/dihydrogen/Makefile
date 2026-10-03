PORTNAME=	dihydrogen
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Dense and sparse linear algebra, conic optimization, lattice reduction
WWW=		https://github.com/LLNL/DiHydrogen

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libfabric.so:net/libfabric \
		libfmt.so:devel/libfmt \
		libhwloc.so:devel/hwloc2 \
		libHydrogen_CXX.so:math/hydrogen \
		libjson-c.so:devel/json-c \
		libopenblas.so:math/openblas \
		libspdlog.so:devel/spdlog \
		libze_loader.so:devel/level-zero
TEST_DEPENDS=	catch2>0:devel/catch2

USES=		cmake:testing compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_PROJECT=	DiHydrogen

LDFLAGS+=	${MPI_LIBS} # no MPI libs linkage might be intentional in the project (to allow lazy linking to any MPI implementaton)

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	H2_ENABLE_TESTS
CMAKE_TESTING_ON=	H2_ENABLE_TESTS

OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	MPICH OPENMPI
OPTIONS_DEFAULT=	MPICH # should be same as in misc/lbann

MPICH_USES=		mpi:mpich

OPENMPI_USES=		mpi:openmpi

# tests as of 0.3.0: 100% tests passed, 0 tests failed out of 36

.include <bsd.port.mk>
