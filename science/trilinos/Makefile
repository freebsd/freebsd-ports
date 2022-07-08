PORTNAME=	trilinos
DISTVERSIONPREFIX=	trilinos-release-
DISTVERSION=	13-4-0
CATEGORIES=	science # physics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Solver for multi-physics engineering and scientific problems

LICENSE=	BSD3CLAUSE LGPL20 # Trilinos is licensed on a per-package basis. Most packages are under a BSD license, some are published under the (L)GPL.
LICENSE_COMB=	multi

BUILD_DEPENDS=	bash:shells/bash \
		boost-libs>0:devel/boost-libs \
		swig:devel/swig \
		${PYNUMPY}
LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack
RUN_DEPENDS=	bash:shells/bash

USES=		cmake compiler:c++14-lang fortran perl5 python shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_PROJECT=	Trilinos

SHEBANG_FILES=	packages/kokkos/bin/kokkos_launch_compiler \
		packages/kokkos/bin/nvcc_wrapper \
		packages/phalanx/scripts/phalanx_create_evaluator.py

CXXFLAGS+=	-DBOOST_STACKTRACE_GNU_SOURCE_NOT_REQUIRED # fails otherwise with backtrace-related symbol error explicitly printed by Boost

CONFLICTS_INSTALL=	mpich kokkos # installs bundled kokkos, need to figure out how to prevent this

## configure Trilinos

# general
#CMAKE_ARGS+=	-DTrilinos_VERBOSE_CONFIGURE=ON
CMAKE_ARGS+=	-DCMAKE_INSTALL_PREFIX:PATH=${PREFIX}
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON

# package selection
CMAKE_ARGS+=	-DTrilinos_ENABLE_ALL_PACKAGES:BOOL=ON
CMAKE_ARGS+=	-DTrilinos_ENABLE_ALL_OPTIONAL_PACKAGES:BOOL=ON
CMAKE_ARGS+=	-DTrilinos_ENABLE_SEACAS:BOOL=OFF # because of pumagon, etc failure (need to retest)

# parallelism-related
CMAKE_ARGS+=	-DTrilinos_ENABLE_OpenMP:BOOL=OFF
#CMAKE_ARGS+=	-DKokkos_ENABLE_Pthread:BOOL=ON
#CMAKE_ARGS+=	-DTPL_ENABLE_Pthread:BOOL=ON
#CMAKE_ARGS+=	-DTPL_ENABLE_MPI:BOOL=ON
#CMAKE_ARGS+=	-DMPI_BASE_DIR:PATH="${LOCALBASE}/mpi/openmpi"
#CMAKE_ARGS+=	-DMPI_BIN_DIR:PATH="${LOCALBASE}/mpi/openmpi/bin"

.include <bsd.port.mk>
