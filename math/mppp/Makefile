PORTNAME=	mppp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.3
PORTREVISION=	5
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multiprecision for modern C++
WWW=		https://github.com/bluescarni/mppp

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		cmake compiler:c++14-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	bluescarni

CMAKE_ON=	MPPP_ENABLE_IPO
CMAKE_OFF=	MPPP_WITH_QUADMATH # no quad-precision fp type on FreeBSD, requested __float128 reinstantiation, bug#238129
TEST_ARGS=	-DMPPP_BUILD_TESTS=ON
BENCHMARK_ARGS=	-DMPPP_BUILD_BENCHMARKS=ON -DMPPP_BENCHMARK_FLINT=ON -DMPPP_BENCHMARK_BOOST=ON

OPTIONS_DEFINE=			ARB FMT MPC MPFR SERIALIZATION
OPTIONS_DEFAULT=		ARB FMT MPC MPFR SERIALIZATION

ARB_DESC=			Enable features relying on Arb
ARB_CMAKE_BOOL=			MPPP_WITH_ARB
ARB_LIB_DEPENDS=		libarb.so:math/arb \
				libflint.so:math/flint2
ARB_IMPLIES=			MPFR

FMT_DESC=			Enable support for the fmt library
FMT_CMAKE_BOOL=			MPPP_WITH_FMT
FMT_LIB_DEPENDS=		libfmt.so:devel/libfmt

MPC_DESC=			Enable features relying on MPC
MPC_CMAKE_BOOL=			MPPP_WITH_MPC
MPC_LIB_DEPENDS=		libmpc.so:math/mpc
MPC_IMPLIES=			MPFR

MPFR_DESC=			Enable features relying on MPFR
MPFR_CMAKE_BOOL=		MPPP_WITH_MPFR
MPFR_LIB_DEPENDS=		libmpfr.so:math/mpfr

SERIALIZATION_DESC=		Enable features relying on the Boost.Serialization library
SERIALIZATION_CMAKE_BOOL=	MPPP_WITH_BOOST_S11N
SERIALIZATION_LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs

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
