PORTNAME=	pichi
DISTVERSION=	1.5.1
CATEGORIES=	net

MAINTAINER=	pichi@elude.in
COMMENT=	Flexible rule-based proxy
WWW=		https://github.com/pichi-router/pichi

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rapidjson>=1.1.0:devel/rapidjson

USES=		cmake compiler:c++17-lang cpe
CPE_VENDOR=	${PORTNAME}_project

USE_GITHUB=	yes
GH_ACCOUNT=	pichi-router

USE_RC_SUBR=	pichi
PLIST_SUB=	DISTVERSION=${DISTVERSION}

CMAKE_BUILD_TYPE=	MinSizeRel
CMAKE_ARGS=		-DVERSION=${DISTVERSION}
CMAKE_ON=		BUILD_SERVER BUILD_TEST
CMAKE_OFF=	ENABLE_CONAN TRANSPARENT_IPTABLES
INSTALL_TARGET=		install/strip
TEST_TARGET=		test

OPTIONS_DEFINE=		DEVEL STATIC TLS_FINGERPRINT TRANSPARENT
OPTIONS_SUB=		yes

STATIC_DESC=		Static linking
STATIC_CMAKE_BOOL_OFF=	BUILD_SHARED_LIBS
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
STATIC_USE_OFF=		LDCONFIG=yes

DEVEL_DESC=		Install development files
DEVEL_CMAKE_BOOL=	INSTALL_DEVEL

TLS_FINGERPRINT_DESC=		Simulate TLS fingerprint of Google Chrome
TLS_FINGERPRINT_CMAKE_BOOL=	TLS_FINGERPRINT

TRANSPARENT_DESC=		Enable transparent ingress feature
TRANSPARENT_CMAKE_BOOL=		TRANSPARENT_PF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTLS_FINGERPRINT}
.if ${PORT_OPTIONS:MSTATIC}
BUILD_DEPENDS+=	brotli>=1.0.0:archivers/brotli \
			boringssl>=0.0.0.0.2022.12.22.01:security/boringssl
.else
LIB_DEPENDS+=	libbrotlicommon.so:archivers/brotli \
			libbrotlidec.so:security/boringssl \
			libbrotlienc.so:security/boringssl \
			libssl.so:security/boringssl \
			libcrypto.so:security/boringssl
.endif
.else
.if ${PORT_OPTIONS:MSTATIC}
USES+=		ssl:build
.else
USES+=		ssl
.endif
.endif

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=unqualified-std-cast-call
.endif

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/test/geo.mmdb ${STAGEDIR}${ETCDIR}/geo.mmdb
	${INSTALL_DATA} ${WRKSRC}/server/pichi.json.default ${STAGEDIR}${ETCDIR}/pichi.json.sample

post-install-DEVEL-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/pichi.h ${STAGEDIR}${PREFIX}/include/pichi.h

.include <bsd.port.post.mk>
