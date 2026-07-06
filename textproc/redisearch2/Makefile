PORTNAME=	redisearch
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10.5
CATEGORIES=	textproc
PKGNAMESUFFIX=	${DISTVERSION:R:R}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Full-text search over Redis (2.10.X)
WWW=		https://github.com/RediSearch/RediSearch/

LICENSE=	RSALv2 SSPLv1
LICENSE_COMB=	dual
LICENSE_NAME_RSALv2=	Redis Source Available License v2
LICENSE_NAME_SSPLv1=	Server Side Public License v1
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_FILE_RSALv2=	${WRKSRC}/licenses/RSALv2.txt
LICENSE_FILE_SSPLv1=	${WRKSRC}/licenses/SSPLv1.txt
LICENSE_PERMS_RSALv2=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_SSPLv1=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libcpu_features.so:devel/cpu_features
BUILD_DEPENDS=	${LOCALBASE}/include/boost/optional.hpp:devel/boost-libs

USES=		cmake compiler localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	RediSearch
GH_PROJECT=	RediSearch
GH_TUPLE=	RedisAI:VectorSimilarity:fadfd5f:vectorsimilarity/deps/VectorSimilarity \
		RedisLabsModules:readies:9f19bb2:readies/deps/readies \
		RedisLabs:RedisModulesSDK:6a62be4:redismodulesdk/deps/RedisModulesSDK \

CMAKE_ARGS=	-DGIT_DESCRIBE_VERSION:STRING=${PKGVERSION} \
		-DOS=freebsd -Wno-dev

PLIST_FILES=	lib/${PORTNAME}${PKGNAMESUFFIX}.so

CFLAGS+=	-DCLOCK_MONOTONIC_RAW=CLOCK_MONOTONIC -fPIC
CXXFLAGS+=	-Wno-vla-cxx-extension -fPIC -I${LOCALBASE}/include/cpu_features
LDFLAGS+=      -lcpu_features

post-patch:
	#@${REINPLACE_CMD} -e '/conan_toolchain.cmake/d' \
	#	${WRKSRC}/src/geometry/CMakeLists.txt
	${ECHO_CMD} "find_package(CpuFeatures REQUIRED)" > ${WRKSRC}/deps/VectorSimilarity/cmake/cpu_features.cmake

do-install:
	${INSTALL} -m 0755 ${INSTALL_WRKSRC}/redisearch.so \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}${PKGNAMESUFFIX}.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}${PKGNAMESUFFIX}.so

.include <bsd.port.mk>
