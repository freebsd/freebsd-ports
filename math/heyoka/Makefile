PORTNAME=	heyoka
DISTVERSIONPREFIX=	v
DISTVERSION=	5.0.0
CATEGORIES=	math

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	e9ca3726897a0b114876f4486d8903740c167893.patch:-p1 # 4 release followup patches from https://github.com/bluescarni/heyoka/pull/428
PATCHFILES+=	86e10d0115074b347d74e78102d59395091c66ac.patch:-p1
PATCHFILES+=	c5609ec799822a3a44044d061a8376221863f747.patch:-p1
PATCHFILES+=	f60ce702cb5d2005598c139c87a2b93460f0771a.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for ODE integration via Taylor's method and LLVM
WWW=		https://bluescarni.github.io/heyoka/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING

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

USES=		cmake:testing compiler:c++17-lang llvm:min=16,build,run
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	bluescarni

CMAKE_ON=		HEYOKA_WITH_MPPP HEYOKA_WITH_SLEEF
CMAKE_ARGS=		-DFREEBSD_LLVM_VERSION=${LLVM_VERSION}
CMAKE_TESTING_ON=	HEYOKA_BUILD_TESTS # 1 test fails, see https://github.com/bluescarni/heyoka/issues/338

# 2 tests fail:
# * https://github.com/bluescarni/heyoka/issues/429
# * https://github.com/bluescarni/heyoka/issues/430

.include <bsd.port.mk>
