PORTNAME=	spfft
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	math

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	c91e7ec9f420d477a8144dee2bc36cd8dde434c4.patch:-p1 # https://github.com/eth-cscs/SpFFT/pull/57

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Sparse 3D FFT library
WWW=		https://github.com/eth-cscs/SpFFT

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfftw3.so:math/fftw3
TEST_DEPENDS=	cli11>0:devel/cli11 \
		googletest>0:devel/googletest \
		nlohmann-json>0:devel/nlohmann-json

USES=		cmake:testing compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	eth-cscs
GH_PROJECT=	SpFFT

CMAKE_TESTING_ON=	SPFFT_BUILD_TESTS
CMAKE_TESTING_ARGS=	-DSPFFT_BUNDLED_CLI11=OFF \
			-DSPFFT_BUNDLED_GOOGLETEST=OFF \
			-DSPFFT_BUNDLED_JSON=OFF
CMAKE_TESTING_TARGET=	${ALL_TARGET}

OPTIONS_DEFINE=		FORTRAN OPENMP
OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	NOMPI MPICH OPENMPI
OPTIONS_DEFAULT=	FORTRAN MPICH
OPTIONS_SUB=		yes

FORTRAN_USES=		fortran
FORTRAN_CMAKE_BOOL=	SPFFT_FORTRAN

NOMPI_DESC=		Build without parallel processing support
NOMPI_CMAKE_ON=		-DSPFFT_MPI=OFF

MPICH_USES=		mpi:mpich
MPICH_CMAKE_ON=		-DSPFFT_MPI=ON

OPENMPI_USES=		mpi:openmpi
OPENMPI_CMAKE_ON=	-DSPFFT_MPI=ON

OPENMP_CMAKE_BOOL=	SPFFT_OMP

.if exists(/usr/include/omp.h)
OPTIONS_DEFAULT+=	OPENMP
.endif

post-test:
	@cd ${BUILD_WRKSRC}/tests && \
		./run_local_tests && \
		./run_mpi_tests

.include <bsd.port.mk>
