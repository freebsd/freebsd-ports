PORTNAME=	mppp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.24
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multiprecision for modern C++

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libarb.so:math/arb \
		libflint.so:math/flint2 \
		libgmp.so:math/gmp \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr

USES=		cmake compiler:c++14-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	bluescarni

CMAKE_ON=	MPPP_WITH_ARB MPPP_WITH_MPC MPPP_WITH_MPFR MPPP_ENABLE_IPO
CMAKE_OFF=	MPPP_WITH_QUADMATH # no quad-precision fp type on FreeBSD, requested __float128 reinstantiation, bug#238129
TEST_ARGS=	-DMPPP_BUILD_TESTS=ON -DMPPP_WITH_QUADMATH=OFF
BENCHMARK_ARGS=	-DMPPP_BUILD_BENCHMARKS=ON -DMPPP_BENCHMARK_FLINT=ON -DMPPP_BENCHMARK_BOOST=ON

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
