PORTNAME=	kuku
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.0
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cuckoo hashing library written in C++
WWW=		https://github.com/microsoft/Kuku

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake compiler:c++17-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	microsoft
GH_PROJECT=	Kuku

CMAKE_ON=	BUILD_SHARED_LIBS

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DKUKU_BUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		./bin/kukutest

# tests as of 4.0.0:
# [==========] 26 tests from 3 test suites ran. (17 ms total)
# [  PASSED  ] 26 tests.

.include <bsd.port.mk>
