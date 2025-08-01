PORTNAME=	trilinos
DISTVERSIONPREFIX=	trilinos-release-
DISTVERSION=	16-1-0
PORTREVISION=	1
CATEGORIES=	science # physics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Solver for multi-physics engineering and scientific problems
WWW=		https://trilinos.github.io/

LICENSE=	BSD3CLAUSE LGPL20 # Trilinos is licensed on a per-package basis. Most packages are under a BSD license, some are published under the (L)GPL.
LICENSE_COMB=	multi

BROKEN_FreeBSD_15=	compilation fails with clang-19, see https://github.com/trilinos/Trilinos/issues/13570
BROKEN_armv6=	kokkos assumes a 64-bit build; i.e., 8-byte pointers, but found 4-byte
BROKEN_armv7=	kokkos assumes a 64-bit build; i.e., 8-byte pointers, but found 4-byte
BROKEN_i386=	kokkos assumes a 64-bit build; i.e., 8-byte pointers, but found 4-byte

BUILD_DEPENDS=	bash:shells/bash \
		boost-libs>0:devel/boost-libs \
		swig:devel/swig \
		${PYNUMPY}
LIB_DEPENDS=	libamd.so:math/suitesparse-amd \
		libblas.so:math/blas \
		liblapack.so:math/lapack \
		libumfpack.so:math/suitesparse-umfpack
RUN_DEPENDS=	bash:shells/bash

USES=		cmake:testing compiler:c++17-lang fortran perl5 python shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_PROJECT=	Trilinos

SHEBANG_FILES=	packages/kokkos/bin/kokkos_launch_compiler \
		packages/kokkos/bin/nvcc_wrapper \
		packages/phalanx/scripts/phalanx_create_evaluator.py

CXXFLAGS+=	-DBOOST_STACKTRACE_GNU_SOURCE_NOT_REQUIRED # fails otherwise with backtrace-related symbol error explicitly printed by Boost
LDFLAGS+=	-lexecinfo # only for kokkos (?), to prevent missing symbols

CMAKE_OFF=		Trilinos_ENABLE_TESTS
CMAKE_TESTING_ON=	Trilinos_ENABLE_TESTS # tests fail to compile, see https://github.com/trilinos/Trilinos/issues/13922

CONFLICTS=	kokkos # installs bundled kokkos, need to figure out how to prevent this
CONFLICTS_INSTALL=	googletest # see https://github.com/trilinos/Trilinos/issues/11271

## configure Trilinos

# general
#CMAKE_ARGS+=	-DTrilinos_VERBOSE_CONFIGURE=ON
CMAKE_ARGS+=	-DCMAKE_INSTALL_PREFIX:PATH=${PREFIX}
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON

# package selection
CMAKE_ARGS+=	-DTrilinos_ENABLE_ALL_PACKAGES:BOOL=ON
CMAKE_ARGS+=	-DTrilinos_ENABLE_ALL_OPTIONAL_PACKAGES:BOOL=ON
CMAKE_ARGS+=	-DTrilinos_ENABLE_SEACAS:BOOL=OFF # because of pumagon, etc failure (need to retest)
CMAKE_ARGS+=	-DTrilinos_ENABLE_PyTrilinos:BOOL=OFF # workaround for https://github.com/trilinos/Trilinos/issues/12184

# for Xyce, see https://github.com/Xyce/Xyce/issues/103#issuecomment-2257272140
CMAKE_ON+=	Trilinos_ENABLE_Ifpack \
		Trilinos_ENABLE_AztecOO \
		Trilinos_ENABLE_Amesos \
		Trilinos_ENABLE_EpetraExt

# parallelism-related
CMAKE_ARGS+=	-DTrilinos_ENABLE_OpenMP:BOOL=OFF
#CMAKE_ARGS+=	-DKokkos_ENABLE_Pthread:BOOL=ON
#CMAKE_ARGS+=	-DTPL_ENABLE_Pthread:BOOL=ON
#CMAKE_ARGS+=	-DTPL_ENABLE_MPI:BOOL=ON
#CMAKE_ARGS+=	-DMPI_BASE_DIR:PATH="${LOCALBASE}/mpi/openmpi"
#CMAKE_ARGS+=	-DMPI_BIN_DIR:PATH="${LOCALBASE}/mpi/openmpi/bin"

## additional features/packages required by Xyce

CMAKE_ON+=	EpetraExt_BUILD_BTF
CMAKE_ON+=	EpetraExt_BUILD_EXPERIMENTAL
CMAKE_ON+=	EpetraExt_BUILD_GRAPH_REORDERINGS
#CMAKE_ON+=	Teuchos_ENABLE_COMPLEX # this feature is broken in Trilinos
CMAKE_ON+=	Trilinos_ENABLE_COMPLEX_DOUBLE

# Enabling the UMFPACK feature required by the above features.
CMAKE_ON+=	TPL_ENABLE_UMFPACK
CMAKE_ON+=	TPL_ENABLE_AMD
CMAKE_ARGS+=	-DUMFPACK_INCLUDE_DIRS=${LOCALBASE}/include/suitesparse
CMAKE_ARGS+=	-DTPL_AMD_INCLUDE_DIRS=${LOCALBASE}/include/suitesparse
CMAKE_ARGS+=	-DAMD_LIBRARY_DIRS=${LOCALBASE}/lib

# users: https://duongdo27.github.io/Trilinos/users.html

CONFLICTS_INSTALL=	googletest # installs files into the same place, problematic file: /usr/local/include/gtest/gtest.h, see https://github.com/trilinos/Trilinos/issues/13929

post-install:
	# remove MPI headers that it installs
	@${RM} ${STAGEDIR}${PREFIX}/include/mpi*.h

.include <bsd.port.mk>
