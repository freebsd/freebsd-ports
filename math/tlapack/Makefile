PORTNAME=	tlapack
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.2
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ Template Linear Algebra PACKage
WWW=		https://github.com/tlapack/tlapack

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lapackpp>0:math/lapackpp
RUN_DEPENDS=	lapackpp>0:math/lapackpp
TEST_DEPENDS=	blaspp>0:math/blaspp \
		catch2>0:devel/catch2 \
		testsweeper>0:devel/testsweeper

USES=		cmake:testing

USE_GITHUB=	yes
GH_TUPLE=	tlapack:testBLAS:496caf7:testBLAS/test/testBLAS

CMAKE_ON=	USE_LAPACKPP_WRAPPERS
CMAKE_OFF=	BUILD_EXAMPLES BUILD_TESTING BUILD_BLASPP_TESTS
CMAKE_TESTING_ON=	BUILD_TESTING

NO_BUILD=	yes
NO_ARCH=	yes

# tests as of 0.1.2: 100% tests passed, 0 tests failed out of 593

.include <bsd.port.mk>
