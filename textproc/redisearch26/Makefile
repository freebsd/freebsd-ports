PORTNAME=	redisearch
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.27
CATEGORIES=	textproc
PKGNAMESUFFIX=	${DISTVERSION:R:S/.//}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Full-text search over Redis (2.6.X)
WWW=		https://github.com/RediSearch/RediSearch/

LICENSE=	LicenseRef-RSALv2-Redis SSPL-1.0
LICENSE_COMB=	dual
LICENSE_NAME_LicenseRef-RSALv2-Redis=	Redis Source Available License v2
LICENSE_FILE_LicenseRef-RSALv2-Redis=	${WRKSRC}/licenses/RSALv2.txt
LICENSE_FILE_SSPL-1.0= ${WRKSRC}/licenses/SSPLv1.txt
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS_LicenseRef-RSALv2-Redis= dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	requires 64-bit architecture

LIB_DEPENDS=   libcpu_features.so:devel/cpu_features

USES=		cmake compiler localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	RediSearch
GH_PROJECT=	RediSearch
GH_TUPLE=	RedisAI:VectorSimilarity:d784136:vectorsimilarity/deps/VectorSimilarity \
		RedisLabsModules:readies:c609278:readies/deps/readies

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
