# $FreeBSD$

PORTNAME=	pichi
DISTVERSION=	1.2.0
CATEGORIES=	net

MAINTAINER=	pichi@elude.in
COMMENT=	Application Layer Proxy controlled via RESTful APIs

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rapidjson>=1.1.0:devel/rapidjson

USES=		cmake compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	pichi-router

USE_RC_SUBR=	pichi
PLIST_SUB=	DISTVERSION=${DISTVERSION}

CMAKE_BUILD_TYPE=	MinSizeRel
CMAKE_ARGS=		-DVERSION=${DISTVERSION}
CMAKE_ON=		BUILD_SERVER BUILD_TEST
CMAKE_OFF=		INSTALL_HEADERS
INSTALL_TARGET=		install/strip
TEST_TARGET=		test

OPTIONS_DEFINE=		STATIC TLS
OPTIONS_DEFAULT=	TLS
OPTIONS_SUB=		yes

TLS_DESC=	Enable TLS support ( requiring OpenSSL )
TLS_CMAKE_BOOL=	ENABLE_TLS

STATIC_DESC=		Build/Install static library
STATIC_CMAKE_BOOL=	STATIC_LINK
STATIC_BUILD_DEPENDS=	boost-libs>=1.67.0:devel/boost-libs \
			libmaxminddb>=1.3.0:net/libmaxminddb \
			libsodium>=1.0.12:security/libsodium \
			mbedtls>=2.7.0:security/mbedtls
STATIC_LIB_DEPENDS_OFF=	libboost_context.so:devel/boost-libs \
			libboost_filesystem.so:devel/boost-libs \
			libboost_program_options.so:devel/boost-libs \
			libboost_system.so:devel/boost-libs \
			libmaxminddb.so:net/libmaxminddb \
			libmbedcrypto.so:security/mbedtls \
			libmbedtls.so:security/mbedtls \
			libmbedx509.so:security/mbedtls \
			libsodium.so:security/libsodium

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MSTATIC}
USE_LDCONFIG=	yes
.endif

.if ${PORT_OPTIONS:MTLS}
.if ${PORT_OPTIONS:MSTATIC}
USES+=		ssl:build
.else
USES+=		ssl
.endif
.endif

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/test/geo.mmdb ${STAGEDIR}${ETCDIR}/geo.mmdb
	${INSTALL_DATA} ${WRKSRC}/server/pichi.json.default ${STAGEDIR}${ETCDIR}/pichi.json.sample
	${MKDIR} ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/pichi.h ${STAGEDIR}${PREFIX}/include/pichi.h

.include <bsd.port.mk>
