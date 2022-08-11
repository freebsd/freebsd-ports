PORTNAME=	tweedledum
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1
CATEGORIES=	science python # quantum-computing

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for analysis, compilation, synthesis of quantum circuits

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	boschmitt

CMAKE_OFF=	TWEEDLEDUM_PYBINDS # doesn't affect the build result, see https://github.com/boschmitt/tweedledum/issues/175
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	TWEEDLEDUM_TESTS
CMAKE_TESTING_TARGET=	${ALL_TARGET} # hack to disable the target

TEST_WRKSRC=	${BUILD_WRKSRC}/tests

post-test: # run tests, all tests pass with 3313 assertions in 73 test cases, see https://github.com/boschmitt/tweedledum/issues/177
	@cd ${TEST_WRKSRC} && ./run_tests

.include <bsd.port.mk>
