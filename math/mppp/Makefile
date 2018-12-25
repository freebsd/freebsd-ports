# $FreeBSD$

PORTNAME=	mppp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multiprecision for modern C++

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING

# build only checks that the headers exist, and then they are included in the run time
BUILD_DEPENDS=	${LOCALBASE}/include/gmp.h:math/gmp \
		${LOCALBASE}/include/mpfr.h:math/mpfr
RUN_DEPENDS=	${LOCALBASE}/include/gmp.h:math/gmp \
		${LOCALBASE}/include/mpfr.h:math/mpfr

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	bluescarni
NO_BUILD=	yes
NO_ARCH=	yes

TEST_USES=	compiler:c++14-lang
TEST_ARGS=	-DMPPP_BUILD_TESTS=ON -DMPPP_WITH_MPFR=ON #-DMPPP_WITH_QUADMATH=ON (quadmath requires __float128, only available in clang6)
BENCHMARK_ARGS=	-DMPPP_BUILD_BENCHMARKS=ON -DMPPP_BENCHMARK_BOOST=ON

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} ${TEST_ARGS} ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

benchmarks: build # additionally depends on boost-libs
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} ${BENCHMARK_ARGS} ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} benchmark

.include <bsd.port.mk>
