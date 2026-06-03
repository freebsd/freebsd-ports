PORTNAME=	redisearch
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.0
CATEGORIES=	textproc
PKGNAMESUFFIX=	${DISTVERSION:R:S/.//}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Full-text search over Redis (2.4.X)
WWW=		https://github.com/RediSearch/RediSearch/

LICENSE=	RSAL
LICENSE_NAME=	Redis Source Available License Agreement
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		cmake compiler
USE_GITHUB=	yes
GH_ACCOUNT=	RediSearch
GH_PROJECT=	RediSearch
GH_TUPLE=	RedisAI:VectorSimilarity:62d8e32:vectorsimilarity/deps/VectorSimilarity \
			google:cpu_features:2f5a7bf:cpu_features/deps/cpu_features

CMAKE_ARGS=	-DGIT_DESCRIBE_VERSION:STRING=${PKGVERSION} \
		-DOS=freebsd

CONFLICTS_INSTALL=	redisearch*

PLIST_FILES=	lib/${PORTNAME}${PKGNAMESUFFIX}.so

CXXFLAGS=-Wno-vla-cxx-extension

pre-configure:
	@${MKDIR} ${WRKDIR}/.build/_deps
	@${MV} ${WRKSRC}/deps/cpu_features ${WRKDIR}/.build/_deps/cpu_features-src

do-install:
	${INSTALL} -m 0755 ${INSTALL_WRKSRC}/redisearch.so \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}${PKGNAMESUFFIX}.so

.include <bsd.port.mk>
