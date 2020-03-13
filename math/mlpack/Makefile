# $FreeBSD$

PORTNAME=	mlpack
DISTVERSION=	3.2.2
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://mlpack.org/files/

MAINTAINER=	robert.ayrapetyan@gmail.com
COMMENT=	Fast, flexible machine learning library

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	ensmallen>0:math/ensmallen \
		${LOCALBASE}/include/stb/stb_image.h:devel/stb
LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs \
		libboost_unit_test_framework.so:devel/boost-libs \
		libboost_serialization.so:devel/boost-libs \
		libarmadillo.so:math/armadillo

USES=		cmake compiler:c++14-lang pkgconfig
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DSTB_IMAGE_INCLUDE_DIR=${LOCALBASE}/include/stb
CMAKE_OFF=	BUILD_PYTHON_BINDINGS BUILD_TESTS BUILD_CLI_EXECUTABLES

.include <bsd.port.mk>
