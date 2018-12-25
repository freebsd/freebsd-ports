# $FreeBSD$

PORTNAME=	sundials
DISTVERSION=	3.1.2
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	https://computation.llnl.gov/projects/sundials/download/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SUite of Nonlinear and DIfferential/ALgebraic Equation Solvers

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:noninja python:build # ninja doesn't support fortran
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DPTHREAD_ENABLE:BOOL=ON \
		-DBUILD_STATIC_LIBS:BOOL=OFF

PLIST_SUB=	SHL3=${DISTVERSION} SHL1=${DISTVERSION:R:R} SHLX3=1.1.2 SHLX1=1

OPTIONS_DEFINE=		BLAS EXAMPLES LAPACK MPI SUPERLUMT # OPENMP detection is broken in cmake: https://gitlab.kitware.com/cmake/cmake/issues/17474
OPTIONS_DEFAULT=	LAPACK
OPTIONS_GROUP=		VECTORS
OPTIONS_GROUP_VECTORS=	HYPRE PETSC
VECTORS_DESC=		Alternative vector libraries
BLAS_DESC=		Enable BLAS support
HYPRE_DESC=		HYPRE vectors support (also enables MPI)
LAPACK_DESC=		Use Lapack linear algebra (sets SUNDIALS_INDEX_TYPE=int32)
PETSC_DESC=		PETSc vectors support (also enables MPI)
SUPERLUMT_DESC=		Sparse matrix factorization through SUPERLUMT
OPTIONS_SUB=		yes

BLAS_CMAKE_BOOL=	BLAS_ENABLE
BLAS_USES=		blaslapack:openblas fortran
BLAS_CMAKE_ON=		-DFREEBSD_GCC_DIR:STRING=${LOCALBASE}/lib/gcc${GCC_DEFAULT:S/.//} # assumes that fortran:gcc is used

EXAMPLES_CMAKE_BOOL=	EXAMPLES_ENABLE_C EXAMPLES_ENABLE_CXX EXAMPLES_ENABLE_F77 EXAMPLES_ENABLE_F90
EXAMPLES_CMAKE_ON=	-DEXAMPLES_INSTALL_PATH=${EXAMPLESDIR}

HYPRE_CMAKE_BOOL=	HYPRE_ENABLE
HYPRE_CMAKE_ON=		-DHYPRE_INCLUDE_DIR=${LOCALBASE}/include \
			-DHYPRE_LIBRARY_DIR=${LOCALBASE}/lib
HYPRE_LIB_DEPENDS=	libHYPRE.so:science/hypre
HYPRE_IMPLIES=		MPI
HYPRE_PREVENTS=		LAPACK  # error: Incompatible sunindextype for LAPACK; disable LAPACK and rebuild

LAPACK_USES=		blaslapack:openblas fortran
LAPACK_CMAKE_BOOL=	LAPACK_ENABLE
LAPACK_CMAKE_ON=	-DSUNDIALS_INDEX_TYPE:STRING=int32_t \
			-DFREEBSD_GCC_DIR:STRING=${LOCALBASE}/lib/gcc${GCC_DEFAULT:S/.//} # assumes that fortran:gcc is used

MPI_CMAKE_ON=		-DMPI_ENABLE:BOOL=ON
MPI_LIB_DEPENDS=	libmpich.so:net/mpich

PETSC_CMAKE_BOOL=	PETSC_ENABLE
PETSC_CMAKE_ON=		-DPETSC_INCLUDE_DIR=${LOCALBASE}/include \
			-DPETSC_LIBRARY_DIR=${LOCALBASE}/lib
PETSC_LIB_DEPENDS=	libpetsc.so:science/PETSc
PETSC_IMPLIES=		MPI
PETSC_PREVENTS=		LAPACK  # error: Incompatible sunindextype for LAPACK; disable LAPACK and rebuild

SUPERLUMT_CMAKE_BOOL=	SUPERLUMT_ENABLE
SUPERLUMT_CMAKE_ON=	-DSUPERLUMT_INCLUDE_DIR=${LOCALBASE}/include/superlu_mt \
			-DSUPERLUMT_LIBRARY_DIR=${LOCALBASE}/lib \
			-DSUPERLUMT_THREAD_TYPE=Pthread \
			-DFREEBSD_GCC_DIR:STRING=${LOCALBASE}/lib/gcc${GCC_DEFAULT:S/.//} # assumes that fortran:gcc is used
SUPERLUMT_LIB_DEPENDS=	libsuperlu_mt_PTHREAD.so:math/superlu_mt
SUPERLUMT_PREVENTS=	LAPACK  # LAPACK requires SUNDIALS_INDEX_TYPE=int32, and SUPERLUMT requires SUNDIALS_INDEX_TYPE=int64

PORTEXAMPLES=	*

post-patch:
	@${FIND} ${WRKSRC}/examples -name "*.c" -o -name "*.cpp" | ${XARGS} ${REINPLACE_CMD} -E 's/"(ESYM|FSYM)"/" \1 "/g'

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/include/sundials/LICENSE

.include <bsd.port.mk>
