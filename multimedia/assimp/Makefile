PORTNAME=	assimp
DISTVERSIONPREFIX=	v
DISTVERSION=	5.4.3
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to import various 3D model formats in a uniform manner
WWW=		https://www.assimp.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv6=	field within 'Assimp::MDL::Vertex_MDL7' is less aligned than 'Assimp::MDL::Vertex_MDL7::..., see https://github.com/assimp/assimp/issues/4640

USES=		cmake:testing compiler:c++17-lang cpe localbase:ldflags pkgconfig # minizip is disabled for https://github.com/assimp/assimp/issues/4374

USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_OFF=		ASSIMP_BUILD_TESTS ASSIMP_BUILD_ZLIB BUILD_STATIC_LIBS
CMAKE_ON=		ASSIMP_BUILD_MINIZIP # workaround for https://github.com/assimp/assimp/issues/4374
CMAKE_TESTING_ON=	ASSIMP_BUILD_TESTS
CMAKE_TESTING_TARGET=	${ALL_TARGET} # hack to avoid target

post-test: # 1 test fails, see https://github.com/assimp/assimp/issues/4751
	@cd ${BUILD_WRKSRC} && \
		${BUILD_WRKSRC}/bin/unit

.include <bsd.port.mk>
