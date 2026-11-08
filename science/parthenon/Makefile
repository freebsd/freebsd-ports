PORTNAME=	parthenon
DISTVERSIONPREFIX=	v
DISTVERSION=	26.10
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Portable block-structured Adaptive Mesh Refinement (AMR) framework
WWW=		https://parthenon-hpc-lab.github.io/parthenon/develop/index.html \
		https://github.com/parthenon-hpc-lab/parthenon

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	compilation fails, see https://github.com/parthenon-hpc-lab/parthenon/issues/1226
BROKEN_i386=	compilation fails, see https://github.com/parthenon-hpc-lab/parthenon/issues/1226

RUN_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libkokkoscore.so:devel/kokkos

USES=		cmake:testing compiler:c++17-lang mpi:mpich python:test

USE_GITHUB=	yes
GH_ACCOUNT=	parthenon-hpc-lab
GH_TUPLE=	catchorg:Catch2:216713a:catch2/external/Catch2

CMAKE_ON=	BUILD_SHARED_LIBS \
		PARTHENON_IMPORT_KOKKOS \
		PARTHENON_DISABLE_EXAMPLES \
		PARTHENON_USE_SYSTEM_PACKAGES
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

# tests as of 25.12: 91% tests passed, 6 tests failed out of 70 (the 6 failures are the
# advection_performance/particle_leapfrog regression tests, which require HDF5 restart I/O;
# HDF5 is disabled by default here since combining it with MPI is currently broken, see
# HDF5_BROKEN above; these regression tests also trip over an unrelated kokkos-threads
# command-line argument parsing issue in this parthenon release)

# tests as of 25.12-700: 95% tests passed, 6 tests failed out of 121 (2 tests timed out, others failed due to wrong kokkos argument, and missing HDF5 parallel support)
# tests as of 26.10: ~96% tests passed, ~5 tests failed out of 141 (regression tests similar to 25.12-700)

.include <bsd.port.mk>
