PORTNAME=	dbcsr
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Distributed Block Compressed Sparse Row matrix library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	fypp:devel/py-fypp@${PY_FLAVOR}

USES=		blaslapack:openblas cmake:noninja compiler:c++14-lang fortran \
		python:build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	cp2k

LDFLAGS+=	-lopenblas

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING WITH_EXAMPLES
CMAKE_ARGS=	-DBLA_VENDOR:STRING="OpenBLAS" -DPython_EXECUTABLE=${PYTHON_CMD}

TEST_TARGET=	test # tests hang: https://github.com/cp2k/dbcsr/issues/72

BINARY_ALIAS=	git=false # with git sonames get messed up

OPTIONS_DEFINE=		MPI OPENMP C_API # libxsmm is supposed to be supported, but cmake build lacks the corresponding option: https://github.com/cp2k/dbcsr/issues/73
OPTIONS_DEFAULT=	MPI OPENMP C_API
OPTIONS_SUB=		yes

MPI_CMAKE_BOOL=		USE_MPI
MPI_LIB_DEPENDS=	libmpi.so:net/openmpi

OPENMP_CMAKE_BOOL=	USE_OPENMP

C_API_DESC=		Build the C API library
C_API_CMAKE_BOOL=	WITH_C_API

.include <bsd.port.pre.mk>

.  if ${GCC_DEFAULT} >= 10
CMAKE_ARGS+=	-DCMAKE_Fortran_FLAGS="${FFLAGS} -fallow-argument-mismatch" # -fallow-argument-mismatch is a workaround of https://github.com/cp2k/dbcsr/issues/387 for gcc10+
.  else
CMAKE_ARGS+=	-DCMAKE_Fortran_FLAGS="${FFLAGS}"
.  endif

do-test: # tests are broken: https://github.com/cp2k/dbcsr/issues/456
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.post.mk>
