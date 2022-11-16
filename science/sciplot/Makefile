PORTNAME=	sciplot
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1
CATEGORIES=	science graphics
PKGNAMESUFFIX=	-plotting-library

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern C++ scientific plotting library powered by gnuplot
WWW=		https://sciplot.github.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	gnuplot:math/gnuplot

USES=		cmake:testing compiler:c++17-lang
USE_GITHUB=	yes

CMAKE_OFF=	SCIPLOT_BUILD_TESTS SCIPLOT_BUILD_EXAMPLES SCIPLOT_BUILD_DOCS
CMAKE_TESTING_ON=	SCIPLOT_BUILD_TESTS
CMAKE_TESTING_TARGET=	${ALL_TARGET} # no test target, see https://github.com/sciplot/sciplot/issues/105

NO_ARCH=	yes

post-test:
	@cd ${TEST_WRKSRC} && tests/sciplot-cpptests

.include <bsd.port.mk>
