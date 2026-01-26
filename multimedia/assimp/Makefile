PORTNAME=	assimp
DISTVERSIONPREFIX=	v
DISTVERSION=	6.0.4
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to import various 3D model formats in a uniform manner
WWW=		https://www.assimp.org \
		https://github.com/assimp/assimp

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++17-lang cpe localbase:ldflags pkgconfig # minizip is disabled for https://github.com/assimp/assimp/issues/4374

USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_OFF=		ASSIMP_BUILD_TESTS ASSIMP_BUILD_ZLIB BUILD_STATIC_LIBS
CMAKE_ON=		ASSIMP_BUILD_MINIZIP # workaround for https://github.com/assimp/assimp/issues/4374
CMAKE_TESTING_ON=	ASSIMP_BUILD_TESTS
CMAKE_TESTING_TARGET=	${ALL_TARGET} # hack to avoid target

post-test:
	@cd ${BUILD_WRKSRC} && \
		${BUILD_WRKSRC}/bin/unit

# tests as of 6.0.1: 584 tests from 114 test suites ran. (2506 ms total)

.include <bsd.port.mk>
