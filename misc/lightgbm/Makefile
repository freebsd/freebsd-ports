PORTNAME=	lightgbm
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.4
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Gradient boosting framework that uses tree based learning algorithms
WWW=		https://lightgbm.readthedocs.io/en/latest/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++11-lang eigen:3

USE_GITHUB=	yes
GH_ACCOUNT=	microsoft
GH_PROJECT=	LightGBM
GH_TUPLE=	boostorg:compute:36350b7:boostorg_compute/external_libs/compute \
		fmtlib:fmt:b6f4cea:fmt/external_libs/fmt \
		lemire:fast_double_parser:ace6064:fast_double_parser/external_libs/fast_double_parser

CMAKE_TESTING_ON=	BUILD_CPP_TEST
CMAKE_TESTING_TARGET=

CXXFLAGS+=	-I${LOCALBASE}/include/eigen3

post-test:
	${WRKSRC}/testlightgbm

.include <bsd.port.mk>
