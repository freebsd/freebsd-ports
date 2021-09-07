PORTNAME=	eigen
PORTVERSION=	3.3.9
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://gitlab.com/libeigen/eigen/-/archive/${PORTVERSION}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Lightweight library for vector and matrix math

LICENSE=	LGPL21 MPL20
LICENSE_COMB=	multi
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LGPL
LICENSE_FILE_MPL20=	${WRKSRC}/COPYING.MPL2

CMAKE_ARGS=	-DPKGCONFIG_INSTALL_DIR:PATH="libdata/pkgconfig"
# This is to set the C++ standard to C++11, instead of 03
CMAKE_ON=	EIGEN_TEST_CXX11
USES=		cmake tar:bzip2
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	BLAS TEST
OPTIONS_DEFAULT=BLAS

BLAS_DESC=	Adds math dependencies
BLAS_CMAKE_ARGS=-DBLAS_DIR:PATH="${LOCALBASE}"
BLAS_USES=	blaslapack pkgconfig

TEST_CMAKE_ON=	EIGEN_TEST_CUDA EIGEN_TEST_CUDA_CLANG
TEST_LIB_DEPENDS=	libcholmod.so:math/suitesparse-cholmod	\
			libumfpack.so:math/suitesparse-umfpack	\
			libsuperlu.so:math/superlu	\
			libadolc.so:math/adol-c		\
			libfftw3.so:math/fftw3		\
			libmpfr.so:math/mpfr		\
			libgmp.so:math/gmp		\
			libboost_thread.so:devel/boost-libs

.include <bsd.port.mk>
