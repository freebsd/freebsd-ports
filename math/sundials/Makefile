PORTNAME=	sundials
DISTVERSION=	5.7.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://github.com/LLNL/sundials/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SUite of Nonlinear and DIfferential/ALgebraic Equation Solvers

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:noninja fortran localbase:ldflags python:build # ninja doesn't support fortran
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DENABLE_PTHREAD:BOOL=ON \
		-DBUILD_STATIC_LIBS:BOOL=OFF

FCFLAGS:=	${FFLAGS} # project checks that these flags are equal

TEST_TARGET=	test

OPTIONS_DEFINE=		BLAS EXAMPLES LAPACK MPI # OPENMP detection is broken in cmake: https://gitlab.kitware.com/cmake/cmake/issues/17474
#OPTIONS_DEFAULT=	LAPACK # LAPACK is broken
OPTIONS_GROUP=		VECTORS
OPTIONS_GROUP_VECTORS=	HYPRE PETSC
VECTORS_DESC=		Alternative vector libraries
OPTIONS_SUB=		yes

BLAS_DESC=		Enable BLAS support
BLAS_CMAKE_BOOL=	BLAS_ENABLE
BLAS_USES=		blaslapack:openblas
BLAS_CMAKE_ON=		-DFREEBSD_GCC_DIR:STRING=${LOCALBASE}/lib/gcc${GCC_DEFAULT:S/.//} # assumes that fortran:gcc is used

EXAMPLES_CMAKE_BOOL=	EXAMPLES_ENABLE_C EXAMPLES_ENABLE_CXX EXAMPLES_ENABLE_F77 EXAMPLES_ENABLE_F90
EXAMPLES_CMAKE_ON=	-DEXAMPLES_INSTALL_PATH=${EXAMPLESDIR}

HYPRE_DESC=		HYPRE vectors support (also enables MPI)
HYPRE_CMAKE_BOOL=	ENABLE_HYPRE
HYPRE_CMAKE_ON=		-DHYPRE_INCLUDE_DIR=${LOCALBASE}/include \
			-DHYPRE_LIBRARY_DIR=${LOCALBASE}/lib
HYPRE_LIB_DEPENDS=	libHYPRE.so:science/hypre # maybe is broken due to https://github.com/hypre-space/hypre/issues/464
HYPRE_IMPLIES=		MPI
HYPRE_PREVENTS=		LAPACK  # error: Incompatible sunindextype for LAPACK; disable LAPACK and rebuild

LAPACK_DESC=		Use Lapack linear algebra (sets SUNDIALS_INDEX_TYPE=int32)
LAPACK_USES=		blaslapack:openblas
LAPACK_CMAKE_BOOL=	ENABLE_LAPACK
LAPACK_CMAKE_ON=	-DSUNDIALS_INDEX_TYPE:STRING=int64_t \
			-DFREEBSD_GCC_DIR:STRING=${LOCALBASE}/lib/gcc${GCC_DEFAULT:S/.//} # assumes that fortran:gcc is used
LAPACK_BROKEN=		Ignores LDFLAGS and fails to find lapack: https://github.com/LLNL/sundials/issues/74

MPI_CMAKE_ON=		-DMPI_ENABLE:BOOL=ON
MPI_LIB_DEPENDS=	libmpich.so:net/mpich

PETSC_DESC=		PETSc vectors support (also enables MPI)
PETSC_CMAKE_BOOL=	ENABLE_PETSC
PETSC_CMAKE_ON=		-DPETSC_DIR=${LOCALBASE} \
			-DPETSC_INCLUDE_DIR=${LOCALBASE}/include \
			-DPETSC_LIBRARY_DIR=${LOCALBASE}/lib
PETSC_LIB_DEPENDS=	libpetsc.so:science/PETSc
PETSC_IMPLIES=		MPI
PETSC_PREVENTS=		LAPACK  # error: Incompatible sunindextype for LAPACK; disable LAPACK and rebuild
PETSC_BROKEN=		ERROR: PETSc not functional due to index size mismatch: SUNDIALS_INDEX_SIZE=64, but PETSc was built with 32-bit indices

PORTEXAMPLES=	*

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/include/sundials/LICENSE

.include <bsd.port.mk>
