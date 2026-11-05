PORTNAME=	Box2D
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.0
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	2D physics engine for games
WWW=		https://box2d.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	fails to compile: error: always_inline function '_mm_setr_ps' requires target feature 'sse', but would be inlined into function 'b2SetW' that is compiled without support for 'sse'

USES=		cmake compiler:c++11-lang pkgconfig
USE_LDCONFIG=	yes

LDFLAGS+=	-pthread

USE_GITHUB=	yes
GH_ACCOUNT=	erincatto
GH_PROJECT=	box2d

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BOX2D_UNIT_TESTS BOX2D_SAMPLES

TEST_BUILD_DIR=	${WRKSRC}/build-test

do-test:
	@${RM} -rf ${TEST_BUILD_DIR}
	@${MKDIR} ${TEST_BUILD_DIR}
	@cd ${TEST_BUILD_DIR} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_SHARED_LIBS:BOOL=OFF -DBOX2D_UNIT_TESTS:BOOL=ON -DBOX2D_SAMPLES:BOOL=OFF ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${TEST_BUILD_DIR}/bin/test

# tests as of 3.2.0: All Box2D tests passed! Test duration = 2.25 s

.include <bsd.port.mk>
