PORTNAME=	quantum++
DISTVERSIONPREFIX=	v
DISTVERSION=	7.0.0
CATEGORIES=	misc devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only general purpose quantum computing library
WWW=		https://github.com/softwareQinc/qpp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++17-lang eigen:3,build,run localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	softwareQinc
GH_PROJECT=	qpp

CMAKE_TESTING_ON=	QPP_ENABLE_TESTING
CMAKE_TESTING_TARGET=	unit_tests

CXXFLAGS=	-I${LOCALBASE}/include/eigen3

NO_BUILD=	yes
NO_ARCH=	yes

post-test: # run tests
	@${BUILD_WRKSRC}/unit_tests/unit_tests

# tests as of 6.0:
# [==========] 457 tests from 325 test suites ran. (1585 ms total)
# [  PASSED  ] 457 tests.

# tests as of 7.0: fail to compile, see https://github.com/softwareQinc/qpp/issues/196

.include <bsd.port.mk>
