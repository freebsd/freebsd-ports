PORTNAME=	tlapack
DISTVERSION=	g20220628
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ Template Linear Algebra PACKage

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lapackpp>0:math/lapackpp
RUN_DEPENDS=	lapackpp>0:math/lapackpp
TEST_DEPENDS=	blaspp>0:math/blaspp

USES=		cmake:testing

USE_GITHUB=	yes
GH_TAGNAME=	77352a9

CMAKE_ON=	USE_LAPACKPP_WRAPPERS
CMAKE_OFF=	BUILD_EXAMPLES BUILD_TESTING BUILD_BLASPP_TESTS
CMAKE_TESTING_ON=	BUILD_TESTING BUILD_BLASPP_TESTS # tests fail to compile, see https://github.com/tlapack/tlapack/issues/111

NO_BUILD=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
