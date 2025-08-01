PORTNAME=	sundials
DISTVERSION=	7.2.1
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	https://github.com/LLNL/sundials/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SUite of Nonlinear and DIfferential/ALgebraic Equation Solvers
WWW=		https://computing.llnl.gov/projects/sundials \
		https://github.com/LLNL/sundials

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing fortran localbase:ldflags python:build # 4 tests fail, see https://github.com/LLNL/sundials/issues/220
USE_LDCONFIG=	yes

CMAKE_ARGS=		-DCMAKE_C_STANDARD=99
CMAKE_ON=		ENABLE_PTHREAD
CMAKE_OFF=		BUILD_STATIC_LIBS \
			EXAMPLES_ENABLE_C EXAMPLES_ENABLE_CXX EXAMPLES_ENABLE_F77 EXAMPLES_ENABLE_F90
CMAKE_TESTING_ON=	SUNDIALS_TEST_UNITTESTS \
			EXAMPLES_ENABLE_C EXAMPLES_ENABLE_CXX EXAMPLES_ENABLE_F77 EXAMPLES_ENABLE_F90

FCFLAGS:=		${FFLAGS} # project checks that these flags are equal

OPTIONS_DEFINE=		BLAS EXAMPLES KLU LAPACK MPI OPENMP
OPTIONS_DEFAULT=	KLU LAPACK MPI OPENMP
# no OpenMP on armv7
.if !exists(/usr/include/omp.h)
OPTIONS_EXCLUDE=	OPENMP
.endif
OPTIONS_GROUP=		VECTORS
OPTIONS_GROUP_VECTORS=	HYPRE PETSC
VECTORS_DESC=		Alternative vector libraries
OPTIONS_SUB=		yes

BLAS_DESC=		Enable BLAS support
BLAS_CMAKE_BOOL=	ENABLE_BLAS
BLAS_USES=		blaslapack:openblas

#EXAMPLES_CMAKE_BOOL=	EXAMPLES_ENABLE_C EXAMPLES_ENABLE_CXX EXAMPLES_ENABLE_F77 EXAMPLES_ENABLE_F90
#EXAMPLES_CMAKE_ON=	-DEXAMPLES_INSTALL_PATH=${EXAMPLESDIR}
#PORTEXAMPLES=		*

HYPRE_DESC=		HYPRE vectors support (also enables MPI)
HYPRE_CMAKE_BOOL=	ENABLE_HYPRE
HYPRE_CMAKE_ON=		-DHYPRE_INCLUDE_DIR=${LOCALBASE}/include \
			-DHYPRE_LIBRARY_DIR=${LOCALBASE}/lib
HYPRE_LIB_DEPENDS=	libHYPRE.so:science/hypre # maybe is broken due to https://github.com/hypre-space/hypre/issues/464
HYPRE_IMPLIES=		MPI
HYPRE_PREVENTS=		LAPACK  # error: Incompatible sunindextype for LAPACK; disable LAPACK and rebuild
HYPRE_BROKEN=		ERROR: SUNDIALS interface to HYPRE is not functional.

KLU_DESC=		Use KLU package that is part of suitesparse
KLU_CMAKE_BOOL=		ENABLE_KLU
KLU_CMAKE_ON=		-DKLU_INCLUDE_DIR=${LOCALBASE}/include/suitesparse -DKLU_LIBRARY_DIR=${LOCALBASE}/lib
KLU_LIB_DEPENDS=	libamd.so:math/suitesparse-amd \
			libbtf.so:math/suitesparse-btf \
			libcolamd.so:math/suitesparse-colamd \
			libklu.so:math/suitesparse-klu \
			libsuitesparseconfig.so:math/suitesparse-config

LAPACK_DESC=		Use Lapack linear algebra (sets SUNDIALS_INDEX_TYPE=int32)
LAPACK_USES=		blaslapack:openblas
LAPACK_CMAKE_BOOL=	ENABLE_LAPACK

MPI_CMAKE_BOOL=		ENABLE_MPI
MPI_LIB_DEPENDS=	libmpich.so:net/mpich

OPENMP_CMAKE_BOOL=	ENABLE_OPENMP

PETSC_DESC=		PETSc vectors support (also enables MPI)
PETSC_CMAKE_BOOL=	ENABLE_PETSC
PETSC_CMAKE_ON=		-DPETSC_DIR=${LOCALBASE} \
			-DPETSC_INCLUDE_DIR=${LOCALBASE}/include \
			-DPETSC_LIBRARY_DIR=${LOCALBASE}/lib
PETSC_LIB_DEPENDS=	libpetsc.so:science/PETSc
PETSC_IMPLIES=		MPI
PETSC_PREVENTS=		LAPACK  # error: Incompatible sunindextype for LAPACK; disable LAPACK and rebuild
PETSC_BROKEN=		ERROR: PETSc not functional due to index size mismatch: SUNDIALS_INDEX_SIZE=64, but PETSc was built with 32-bit indices

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/include/sundials/LICENSE

.include <bsd.port.mk>
