PORTNAME=	dbcsr
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.0
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Distributed Block Compressed Sparse Row matrix library
WWW=		https://www.cp2k.org/dbcsr

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

BUILD_DEPENDS=	fypp:devel/py-fypp@${PY_FLAVOR}

USES=		blaslapack:openblas cmake:noninja,testing compiler:c++14-lang fortran \
		python:build
USE_GCC=	yes # OpenMP is used from both Fortan and C code, therefore C code should be compiled with GCC, otherwise it fails at run-time (same in cp2k)
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	cp2k

FFLAGS+=	-D__NO_STATM_ACCESS # disable /proc/self/statm access
LDFLAGS+=	-lopenblas

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING WITH_EXAMPLES
CMAKE_ARGS=	-DBLA_VENDOR:STRING="OpenBLAS" -DPython_EXECUTABLE=${PYTHON_CMD}

BINARY_ALIAS=	git=false # with git sonames get messed up

OPTIONS_DEFINE=		C_API MPIX OPENMP # libxsmm is supposed to be supported, but cmake build lacks the corresponding option: https://github.com/cp2k/dbcsr/issues/73
OPTIONS_DEFAULT=	C_API MPIX OPENMP
OPTIONS_SUB=		yes

MPIX_DESC=		Enable MPI
MPIX_CMAKE_BOOL=	USE_MPI USE_MPI_F08
MPIX_USES=		mpi:mpich

OPENMP_CMAKE_BOOL=	USE_OPENMP

C_API_DESC=		Build the C API library
C_API_CMAKE_BOOL=	WITH_C_API
C_API_IMPLIES=		MPIX # the ISO_C_BINDINGS require MPI unconditionally

.include <bsd.port.pre.mk>

.  if ${GCC_DEFAULT} >= 10
CMAKE_ARGS+=	-DCMAKE_Fortran_FLAGS="${FFLAGS} -fallow-argument-mismatch" # -fallow-argument-mismatch is a workaround of https://github.com/cp2k/dbcsr/issues/387 for gcc10+
.  else
CMAKE_ARGS+=	-DCMAKE_Fortran_FLAGS="${FFLAGS}"
.  endif

.include <bsd.port.post.mk>
