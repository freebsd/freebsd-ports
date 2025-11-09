PORTNAME=	highfive
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.0
CATEGORIES=	science devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only C++ HDF5 interface
WWW=		https://highfive-devs.github.io/highfive/ \
		https://github.com/highfive-devs/highfive

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhdf5.so:science/hdf5
RUN_DEPENDS=	${LOCALBASE}/include/boost/multi_array.hpp:devel/boost-libs \
		${LOCALBASE}/include/xtensor.hpp:math/xtensor
TEST_DEPENDS=	catch2>0:devel/catch2

USES=		cmake eigen:3,run

USE_GITHUB=	yes
GH_ACCOUNT=	highfive-devs

CMAKE_OFF=	HIGHFIVE_USE_BOOST HIGHFIVE_UNIT_TESTS HIGHFIVE_EXAMPLES

NO_BUILD=	yes
NO_ARCH=	yes

do-test: # one test fails, see https://github.com/BlueBrain/HighFive/issues/634
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DHIGHFIVE_UNIT_TESTS:BOOL=ON -DHIGHFIVE_USE_BOOST=ON -DHIGHFIVE_USE_EIGEN:BOOL=ON -DHIGHFIVE_USE_XTENSOR=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

# tests as of 3.2.0: 99% tests passed, 3 tests failed out of 278, skipped tests are reported as failed, see https://github.com/highfive-devs/highfive/issues/88

.include <bsd.port.mk>
