PORTNAME=	assimp
DISTVERSIONPREFIX=	v
DISTVERSION=	5.1.0
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to import various 3D model formats in a uniform manner

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libminizip.so:archivers/minizip

USES=		cmake:testing compiler:c++11-lib localbase:ldflags pkgconfig

USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_OFF=		ASSIMP_BUILD_TESTS
CMAKE_TESTING_ON=	ASSIMP_BUILD_TESTS

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} ${CMAKE_TESTING_ARGS} ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${BUILD_WRKSRC}/bin/unit

.include <bsd.port.mk>
