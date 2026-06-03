PORTNAME=	heyoka
DISTVERSIONPREFIX=	v
DISTVERSION=	7.11.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for ODE integration via Taylor's method and LLVM
WWW=		https://bluescarni.github.io/heyoka/ \
		https://github.com/bluescarni/heyoka

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs \
		libfmt.so:devel/libfmt \
		libgmp.so:math/gmp \
		libmp++.so:math/mppp \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr \
		libsqlite3.so:databases/sqlite3 \
		libtbb.so:devel/onetbb \
		libsleef.so:math/sleef \
		libspdlog.so:devel/spdlog
TEST_DEPENDS=	xtensor>0:math/xtensor \
		xtensor-blas>0:math/xtensor-blas

USES=		cmake:testing compiler:c++20-lang llvm:min=18,build,run ssl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	bluescarni

CMAKE_ON=		HEYOKA_WITH_MPPP HEYOKA_WITH_SLEEF
CMAKE_TESTING_ON=	HEYOKA_BUILD_TESTS

.include <bsd.port.pre.mk>

# LLVM 18 and later use 1 for their minor version, while 17 and earlier use 0.
# CMake's find_package() needs the minor version set correctly, otherwise it
# will not be able to find the LLVM package.
.if ${LLVM_VERSION} >= 18
LLVM_VERSION_MINOR=	1
.else
LLVM_VERSION_MINOR=	0
.endif

CMAKE_ARGS+=		-DFREEBSD_LLVM_VERSION=${LLVM_VERSION}.${LLVM_VERSION_MINOR}

# tests as of 7.11.0: 100% tests passed, 0 tests failed out of 162

.include <bsd.port.post.mk>
