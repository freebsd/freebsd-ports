# $FreeBSD$

PORTNAME=	mlpack
DISTVERSION=	3.2.2
PORTREVISION=	2
CATEGORIES=	math # machine-learning
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

do-test: # 'clean' target below is a workaround for: https://github.com/mlpack/mlpack/issues/2300
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} clean && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
