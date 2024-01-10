PORTNAME=	dpp
DISTVERSION=	10.0.29
CATEGORIES=	www devel
MASTER_SITES=	https://github.com/brainboxdotcc/DPP/releases/download/v${DISTVERSION}/
PKGNAMESUFFIX=	-discord
DISTNAME=	DPP-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ Discord API bot library
WWW=		https://dpp.dev/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json
LIB_DEPENDS=	libopus.so:audio/opus \
		libsodium.so:security/libsodium
RUN_DEPENDS=	nlohmann-json>0:devel/nlohmann-json

USES=		cmake:testing compiler:c++20-lang localbase ssl

CMAKE_ON=	DPP_USE_EXTERNAL_JSON DPP_NO_VCPKG
CMAKE_ON+=	DPP_CORO # experimental support for C++20 coroutines
CMAKE_OFF=	RUN_LDCONFIG DPP_BUILD_TEST
CMAKE_TESTING_ON=	DPP_BUILD_TEST

MAKE_ENV=	TEST_DATA_DIR=${WRKSRC}/testdata/ # only for tests

post-extract:
	@${RM} -r ${WRKSRC}/include/dpp/nlohmann

# 1 test fails: ts_not_null(), see https://github.com/brainboxdotcc/DPP/issues/1063

.include <bsd.port.mk>
