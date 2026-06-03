PORTNAME=	eigen
DISTVERSION=	5.0.1
CATEGORIES=	math
PKGNAMESUFFIX=	5

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight library for vector and matrix math
WWW=		https://eigen.tuxfamily.org/

LICENSE=	APACHE20 BSD3CLAUSE MPL20
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/COPYING.APACHE
LICENSE_FILE_APACHE20=	${WRKSRC}/COPYING.BSD
LICENSE_FILE_MPL20=	${WRKSRC}/COPYING.MPL2 # primary license

TEST_DEPENDS=	suitesparse-cholmod>0:math/suitesparse-cholmod \
		suitesparse-umfpack>0:math/suitesparse-umfpack \
		superlu>0:math/superlu	\
		adol-c>0:math/adol-c \
		fftw3>0:math/fftw3 \
		mpfr>0:math/mpfr \
		gmp>0:math/gmp \
		boost-libs>0:devel/boost-libs

USES=		cmake:testing
USE_GITLAB=	yes
GL_ACCOUNT=	libeigen

CMAKE_ARGS=	-DPKGCONFIG_INSTALL_DIR:PATH="libdata/pkgconfig"
CMAKE_ON=	EIGEN_TEST_CXX11 # This is to set the C++ standard to C++11, instead of 03
CMAKE_OFF=	EIGEN_BUILD_TESTING
CMAKE_TESTING_ON=	EIGEN_BUILD_TESTING EIGEN_TEST_CUDA EIGEN_TEST_CUDA_CLANG

DATADIR=		${PREFIX}/share/${PORTNAME}3

OPTIONS_DEFINE=	BLAS
OPTIONS_DEFAULT=BLAS

BLAS_DESC=	Adds math dependencies
BLAS_CMAKE_ON=	-DBLAS_DIR:PATH="${LOCALBASE}"
BLAS_USES=	blaslapack pkgconfig

CONFLICTS_INSTALL=	eigen

.include <bsd.port.mk>
