PORTNAME=	cp2k
DISTVERSIONPREFIX=	v
DISTVERSION=	2025.2
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quantum chemistry and solid state physics software package
WWW=		https://www.cp2k.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

BUILD_DEPENDS=	fypp:devel/py-fypp@${PY_FLAVOR}
LIB_DEPENDS=	libdbcsr.so:math/dbcsr \
		libfftw3.so:math/fftw3 \
		libopenblas.so:math/openblas
RUN_DEPENDS=	cp2k-data>0:science/cp2k-data
TEST_DEPENDS=	bash:shells/bash

USES=		cmake fortran localbase:ldflags python:build,test shebangfix tar:bz2
USE_GCC=	yes # OpenMP is used from both Fortan and C code, therefore C code should be compiled with GCC, otherwise it fails at run-time (same in dbcsr)

USE_GITHUB=	yes

SHEBANG_GLOB=	*.py

GCC_VERSION=	${GCC_DEFAULT}

MAKE_ARGS=	XARCH=FreeBSD-gfortran VERSION=${VERSION} FC=gfortran${GCC_VERSION} CC=${CC} LD=gfortran${GCC_VERSION} \
		DATA_DIR=${DATADIR}

FFLAGS+=	-D__NO_STATM_ACCESS

BINARY_ALIAS=	python=${PYTHON_CMD} python3=${PYTHON_CMD}

OPTIONS_DEFINE=		LIBINT MPIX
OPTIONS_DEFAULT=	MPIX # LIBINT

LIBINT_DESC=		Use libint to evaluate integrals
LIBINT_CMAKE_BOOL=	CP2K_USE_LIBINT2
LIBINT_LIB_DEPENDS=	libint2.so:science/libint2
LIBINT_BROKEN=		missing fortran support

MPIX_DESC=		Enable MPI
MPIX_CMAKE_BOOL=	CP2K_USE_MPI
MPIX_USES=		mpi:mpich
MPIX_LIB_DEPENDS=	libscalapack.so:math/scalapack
MPIX_VARS=		EXE_VERSION=psmp
MPIX_VARS_OFF=		EXE_VERSION=ssmp

PLIST_SUB=		SUFFIX=.${EXE_VERSION}

do-test: install
	@cd ${WRKSRC}/ && \
		${SETENV} ${MAKE_ENV} CP2K_STEM=${PREFIX}/bin/cp2k \
			./tests/do_regtest.py ${BUILD_WRKSRC}/bin ${EXE_VERSION}

# build instructions: https://github.com/cp2k/cp2k/blob/master/INSTALL.md
# tests as of 2025.2: Summary: correct: 3009 / 3012; failed: 3; 141min

.include <bsd.port.mk>
