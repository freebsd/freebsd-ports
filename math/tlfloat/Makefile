PORTNAME=	tlfloat
DISTVERSIONPREFIX=v
DISTVERSION=	1.15.0
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ template library for floating point operations
WWW=		https://shibatch.github.io/tlfloat-doxygen/

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_arm64=	error: use of undeclared identifier 'isnanl'
BROKEN_armv7=	error: use of undeclared identifier 'isnanl'
BROKEN_i386=	error: undefined symbol: __trunctfdf2

TEST_DEPENDS=	mpfr>0:math/mpfr

USES=		cmake:testing compiler:c++20-lang pathfix

USE_GITHUB=	yes
GH_ACCOUNT=	shibatch

WITH_LTO=	yes

CMAKE_TESTING_ON=	BUILD_TESTS

CMAKE_OFF=	BUILD_TESTS \
		BUILD_UTILS
CMAKE_ON=	CMAKE_POSITION_INDEPENDENT_CODE \
		BUILD_SHARED_LIBS

.include <bsd.port.mk>
