PORTNAME=	heyoka
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
PORTREVISION=	4
CATEGORIES=	math

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

USES=		cmake:testing compiler:c++17-lang llvm:min=15,build,run
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	bluescarni

CMAKE_ON=		HEYOKA_WITH_MPPP HEYOKA_WITH_SLEEF
CMAKE_ARGS=		-DFREEBSD_LLVM_VERSION=${LLVM_VERSION}
CMAKE_TESTING_ON=	HEYOKA_BUILD_TESTS # 1 test fails, see https://github.com/bluescarni/heyoka/issues/338

.include <bsd.port.mk>
