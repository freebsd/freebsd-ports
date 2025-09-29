PORTNAME=	minorminer
DISTVERSION=	0.2.19
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Heuristic tool for minor graph embedding (C++ headers-only library)
WWW=		https://github.com/dwavesystems/minorminer

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	dwavesystems

CMAKE_TESTING_ON=	MINORMINER_BUILD_TESTS
CMAKE_TESTING_TARGET=	${ALL_TARGET}

NO_ARCH=	yes

do-install: # workaround for https://github.com/dwavesystems/minorminer/issues/220
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	@cd ${WRKSRC}/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${PORTNAME}

post-test:
	@cd ${BUILD_WRKSRC}/tests && ./run_tests

# tests as of 0.2.19: 34 tests from 4 test suites ran. (5 ms total)

.include <bsd.port.mk>
