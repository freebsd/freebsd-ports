PORTNAME=	heyoka
DISTVERSIONPREFIX=	v
DISTVERSION=	6.0.0
PORTREVISION=	6
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for ODE integration via Taylor's method and LLVM
WWW=		https://bluescarni.github.io/heyoka/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_13=	compilation fails: no member named 'transform' in namespace 'std::ranges'; did you mean 'llvm::transform' (std::ranges::transform isn't present)

LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs \
		libfmt.so:devel/libfmt \
		libgmp.so:math/gmp \
		libmp++.so:math/mppp \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr \
		libtbb.so:devel/onetbb \
		libsleef.so:math/sleef \
		libspdlog.so:devel/spdlog
TEST_DEPENDS=	xtensor>0:math/xtensor \
		xtensor-blas>0:math/xtensor-blas

USES=		cmake:testing compiler:c++20-lang llvm:min=16,build,run
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	bluescarni

CMAKE_ON=		HEYOKA_WITH_MPPP HEYOKA_WITH_SLEEF
CMAKE_TESTING_ON=	HEYOKA_BUILD_TESTS # 1 test fails, see https://github.com/bluescarni/heyoka/issues/338

# 2 tests fail:
# * https://github.com/bluescarni/heyoka/issues/429
# * https://github.com/bluescarni/heyoka/issues/430

.include <bsd.port.pre.mk>

# LLVM 18 and later use 1 for their minor version, while 17 and earlier use 0.
# CMake's find_package() needs the minor version set correctly, otherwise it
# will not be able to find the LLVM package.
.if ${LLVM_VERSION} >= 18
LLVM_VERSION_MINOR=     1
.else
LLVM_VERSION_MINOR=     0
.endif

CMAKE_ARGS+=		-DFREEBSD_LLVM_VERSION=${LLVM_VERSION}.${LLVM_VERSION_MINOR}

.include <bsd.port.post.mk>
