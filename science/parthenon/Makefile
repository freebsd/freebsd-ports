PORTNAME=	parthenon
DISTVERSIONPREFIX=	v
DISTVERSION=	24.08
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Portable block-structured Adaptive Mesh Refinement (AMR) framework
WWW=		https://parthenon-hpc-lab.github.io/parthenon/develop/index.html

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		cmake:testing compiler:c++17-lang mpi:mpich python:test shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	parthenon-hpc-lab
GH_TUPLE=	catchorg:Catch2:216713a:catch2/external/Catch2 \
		kokkos:kokkos:62d2b6c:kokkos/external/Kokkos

SHEBANG_FILES=	external/Kokkos/bin/kokkos_launch_compiler \
		external/Kokkos/bin/nvcc_wrapper

CMAKE_ON=	BUILD_SHARED_LIBS \
		PARTHENON_DISABLE_EXAMPLES
CMAKE_OFF=	PARTHENON_ENABLE_TESTING
CMAKE_TESTING_ON=	PARTHENON_ENABLE_TESTING \
			PARTHENON_ENABLE_UNIT_TESTS \
			PARTHENON_ENABLE_INTEGRATION_TESTS \
			PARTHENON_ENABLE_REGRESSION_TESTS

LDFLAGS+=	-lexecinfo

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${WRKSRC}/scripts/python/packages/parthenon_tools/parthenon_tools

OPTIONS_DEFINE=		ASCENT HDF5
OPTIONS_DEFAULT=	ASCENT

ASCENT_DESC=		Enable Ascent for in situ visualization and analysis
ASCENT_CMAKE_BOOL=	PARTHENON_ENABLE_ASCENT
ASCENT_LIB_DEPENDS=	libascent_mpi.so:science/ascent \
			libconduit.so:science/conduit \
			libhdf5.so:science/hdf5 \
			libsiloh5.so:science/silo

HDF5_CMAKE_OFF=		-DPARTHENON_DISABLE_HDF5=ON
HDF5_BROKEN=		configure fails: Both MPI and HDF5 are enabled but only a serial version of HDF5 was found.

# few tests don't find some test files

.include <bsd.port.mk>
