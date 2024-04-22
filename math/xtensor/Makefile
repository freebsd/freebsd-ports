PORTNAME=	xtensor
DISTVERSION=	0.25.0
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

USES=		cmake:testing # 2 tests fail, see https://github.com/xtensor-stack/xtensor/issues/2722
USE_GITHUB=	yes
GH_ACCOUNT=	xtensor-stack

CMAKE_TESTING_ON=	BUILD_TESTS

NO_BUILD=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
