PORTNAME=	redisearch
DISTVERSIONPREFIX=	v
DISTVERSION=	8.8.0
CATEGORIES=	textproc

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Querying secondary indexing and full-text search for Redis
WWW=		https://github.com/RediSearch/RediSearch/

LICENSE=	AGPLv3 RSALv2 SSPLv1
LICENSE_COMB=	dual
LICENSE_NAME_RSALv2=	Redis Source Available License v2
LICENSE_NAME_SSPLv1=	Server Side Public License v1
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS_RSALv2=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_SSPLv1=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	Requires 64-bit architecture

BUILD_DEPENDS=	${LOCALBASE}/include/boost/optional.hpp:devel/boost-libs \
		bash:shells/bash

USES=	cargo cmake llvm:min=21,build python:build ssl
CARGO_SRC_SUBDIR=	src/redisearch_rs
USE_GITHUB=	yes
GH_ACCOUNT=	RediSearch
GH_PROJECT=	RediSearch
GH_TUPLE=	libuv:libuv:e9f29cb:libuv/deps/libuv \
		redis:hiredis:bd01f10:hiredis/deps/hiredis \
		snowballstem:snowball:4764395:snowball/deps/snowball \
		RedisAI:VectorSimilarity:8c5791f:vectorsimilarity/deps/VectorSimilarity \
		intel:ScalableVectorSearch:02dea9d:scalablevectorsearch/deps/VectorSimilarity/deps/ScalableVectorSearch \
		jfalcou:eve:v2023.02.15:eve/deps/eve \
		Tessil:robin-map:v1.4.0:robin_map/deps/robin-map \
		fmtlib:fmt:12.1.0:fmt/deps/fmt \
		gabime:spdlog:v1.15.3:spdlog/deps/spdlog \
		marzer:tomlplusplus:v3.3.0:tomlplusplus/deps/tomlplusplus \
		google:cpu_features:v0.10.1:cpu_features/deps/cpu_features

CMAKE_ARGS=	-DBOOST_DIR=${PREFIX} \
			-Wno-dev --no-warn-unused-cli \
			-DSVS_INSTALL=OFF \
			-DCMAKE_SKIP_INSTALL_RULES=ON

CFLAGS+=	-DCLOCK_MONOTONIC_RAW=CLOCK_MONOTONIC

BINARY_ALIAS=	python3=${PYTHON_CMD}

PLIST_FILES=	lib/redisearch.so

post-extract:
	${TOUCH} ${WRKSRC}/.git

pre-configure:
	@${MKDIR} ${WRKDIR}/.build/_deps
	@${MV} ${WRKSRC}/deps/cpu_features ${WRKDIR}/.build/_deps/cpu_features-src
	@${MV} ${WRKSRC}/deps/eve ${WRKDIR}/.build/_deps/eve-src
	@${MV} ${WRKSRC}/deps/fmt ${WRKDIR}/.build/_deps/fmt-src
	@${MV} ${WRKSRC}/deps/robin-map ${WRKDIR}/.build/_deps/robinmap-src
	@${MV} ${WRKSRC}/deps/spdlog ${WRKDIR}/.build/_deps/spdlog-src
	@${MV} ${WRKSRC}/deps/tomlplusplus ${WRKDIR}/.build/_deps/tomlplusplus-src

do-install:
	${INSTALL} -m 0755 ${WRKDIR}/.build/redisearch.so ${STAGEDIR}${PREFIX}/lib
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}${PKGNAMESUFFIX}.so

.include <bsd.port.mk>
