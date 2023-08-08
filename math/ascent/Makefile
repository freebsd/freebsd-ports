PORTNAME=	ascent
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.1
CATEGORIES=	math
PKGNAMESUFFIX=	-simulation-engine

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ simulation engine and differential equation solver
WWW=		https://github.com/AnyarInc/Ascent

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++17-lang
USE_GITHUB=	yes
GH_ACCOUNT=	AnyarInc
GH_PROJECT=	Ascent

CMAKE_OFF=	BUILD_TESTING BUILD_EXAMPLES
CMAKE_TESTING_ON=	BUILD_TESTING # tests fail to configure, see https://github.com/AnyarInc/Ascent/issues/29

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	@cd ${WRKSRC}/include && ${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${PREFIX}/include

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${BUILD_WRKSRC}/unit_tests/ascent_test

.include <bsd.port.mk>
