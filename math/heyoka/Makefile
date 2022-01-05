PORTNAME=	heyoka
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.0
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for ODE integration via Taylor's method and LLVM

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	llvm${LLVM_VERSION}>0:devel/llvm${LLVM_VERSION}
LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs \
		libfmt.so:devel/libfmt \
		libmp++.so:math/mppp \
		libtbb.so:devel/onetbb \
		libsleef.so:math/sleef \
		libspdlog.so:devel/spdlog
RUN_DEPENDS=	llvm${LLVM_VERSION}>0:devel/llvm${LLVM_VERSION}
TEST_DEPENDS=	xtensor>0:math/xtensor \
		xtensor-blas>0:math/xtensor-blas

USES=		cmake:testing compiler:c++17-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	bluescarni

LLVM_VERSION=	12

CMAKE_ON=		HEYOKA_WITH_MPPP HEYOKA_WITH_SLEEF
CMAKE_ARGS=		-DFREEBSD_LLVM_VERSION=${LLVM_VERSION}
CMAKE_TESTING_ON=	HEYOKA_BUILD_TESTS # tests can't be compiled: xtensor-blas isn't yet ported

.include <bsd.port.mk>
