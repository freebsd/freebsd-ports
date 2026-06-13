PORTNAME=	redisearch
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.2
CATEGORIES=	textproc
PKGNAMESUFFIX=	${DISTVERSION:R:S/.//}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Full-text search over Redis (2.6.X)
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

USES=		cmake compiler
USE_GITHUB=	yes
GH_ACCOUNT=	RediSearch
GH_PROJECT=	RediSearch
GH_TUPLE=	RedisAI:VectorSimilarity:4e065d8:vectorsimilarity/deps/VectorSimilarity \
			google:cpu_features:438a66e:cpu_features/deps/cpu_features

CMAKE_ARGS=	-DGIT_DESCRIBE_VERSION:STRING=${PKGVERSION} \
		-DOS=freebsd

CONFLICTS_INSTALL=	redisearch*

PLIST_FILES=	lib/${PORTNAME}${PKGNAMESUFFIX}.so

CFLAGS+=	-DCLOCK_MONOTONIC_RAW=CLOCK_MONOTONIC
CXXFLAGS+=-Wno-vla-cxx-extension

pre-configure:
	@${MKDIR} ${WRKDIR}/.build/_deps
	@${MV} ${WRKSRC}/deps/cpu_features ${WRKDIR}/.build/_deps/cpu_features-src

do-install:
	${INSTALL} -m 0755 ${INSTALL_WRKSRC}/redisearch.so \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}${PKGNAMESUFFIX}.so

.include <bsd.port.mk>
