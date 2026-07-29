PORTNAME=	redisearch
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.10
CATEGORIES=	textproc
PKGNAMESUFFIX=	${DISTVERSION:R:S/.//}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Full-text search over Redis (2.4.X)
WWW=		https://github.com/RediSearch/RediSearch/

LICENSE=	RSAL
LICENSE_NAME=	Redis Source Available License Agreement
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	libcpu_features.so:devel/cpu_features

USES=		cmake compiler localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	RediSearch
GH_PROJECT=	RediSearch
GH_TUPLE=	RedisAI:VectorSimilarity:6252f94:vectorsimilarity/deps/VectorSimilarity

CMAKE_ARGS=	-DGIT_DESCRIBE_VERSION:STRING=${PKGVERSION} \
		-DOS=freebsd

CFLAGS+=	-DCLOCK_MONOTONIC_RAW=CLOCK_MONOTONIC
CXXFLAGS+=	-Wno-vla-cxx-extension -I${LOCALBASE}/include/cpu_features
LDFLAGS+=	-lcpu_features

CONFLICTS_INSTALL=	redisearch*

PLIST_FILES=	lib/${PORTNAME}${PKGNAMESUFFIX}.so

CFLAGS+=	-DCLOCK_MONOTONIC_RAW=CLOCK_MONOTONIC -fPIC
post-patch:
	${ECHO_CMD} "find_package(CpuFeatures REQUIRED)" > ${WRKSRC}/deps/VectorSimilarity/cmake/cpu_features.cmake

do-install:
	${INSTALL} -m 0755 ${INSTALL_WRKSRC}/redisearch.so \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}${PKGNAMESUFFIX}.so

.include <bsd.port.mk>
