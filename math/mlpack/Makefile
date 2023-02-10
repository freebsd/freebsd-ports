PORTNAME=	mlpack
DISTVERSION=	4.0.1
PORTREVISION=	1
CATEGORIES=	math # machine-learning
MASTER_SITES=	https://mlpack.org/files/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast, flexible machine learning library
WWW=		https://www.mlpack.org/

LICENSE=	BSD3CLAUSE

BROKEN_i386=	undefined symbol: __atomic_load

BUILD_DEPENDS=	cereal>0:devel/cereal \
		ensmallen>0:math/ensmallen \
		${LOCALBASE}/include/stb/stb_image.h:devel/stb
LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs \
		libboost_unit_test_framework.so:devel/boost-libs \
		libboost_serialization.so:devel/boost-libs \
		libarmadillo.so:math/armadillo

USES=		cmake:testing compiler:c++14-lang pkgconfig
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DSTB_IMAGE_INCLUDE_DIR=${LOCALBASE}/include/stb
CMAKE_OFF=	BUILD_PYTHON_BINDINGS BUILD_TESTS
CMAKE_TESTING_ON=	BUILD_TESTS

BINARY_ALIAS=	git=false

OPTIONS_DEFINE=		EXECUTABLES
OPTIONS_DEFAULT=	EXECUTABLES
OPTIONS_SUB=		yes

EXECUTABLES_DESC=	Build command-line executables
EXECUTABLES_CMAKE_BOOL=	BUILD_CLI_EXECUTABLES
EXECUTABLES_VARS_OFF=	NO_ARCH=yes

.include <bsd.port.mk>
