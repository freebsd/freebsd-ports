PORTNAME=	xtensor
DISTVERSION=	0.27.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multi-dimensional arrays with broadcasting and lazy computing
WWW=		https://github.com/xtensor-stack/xtensor

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json \
		xtl-quant-stack>0:devel/xtl-quant-stack
RUN_DEPENDS=	nlohmann-json>0:devel/nlohmann-json \
		xtl-quant-stack>0:devel/xtl-quant-stack
TEST_DEPENDS=	nlohmann-json>0:devel/nlohmann-json \
		xtl-quant-stack>0:devel/xtl-quant-stack \
		doctest>0:devel/doctest \
		googletest>0:devel/googletest

USES=		cmake:testing
USE_GITHUB=	yes
GH_ACCOUNT=	xtensor-stack

CMAKE_TESTING_ON=	BUILD_TESTS

NO_BUILD=	yes
NO_ARCH=	yes

# tests as of 0.27.1: 100% tests passed, 0 tests failed out of 81

.include <bsd.port.mk>
