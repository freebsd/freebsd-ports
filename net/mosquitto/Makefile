PORTNAME=	mosquitto
DISTVERSION=	2.1.2
CATEGORIES=	net
MASTER_SITES=	https://mosquitto.org/files/source/

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Open source MQTT broker
WWW=		https://mosquitto.org/

LICENSE=	EPL

BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
		xsltproc:textproc/libxslt
LIB_DEPENDS=	libcjson.so:devel/libcjson \
		libsqlite3.so:databases/sqlite3 \
		libuuid.so:misc/libuuid
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		cmake cpe ssl
USE_RC_SUBR=	mosquitto
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DCJSON_INCLUDE_DIR:PATH="${PREFIX}/include/json" \
		-DCJSON_LIBRARY:PATH="${PREFIX}/lib/libcjson.so" \
		-DCMAKE_LIBDATADIR:PATH="${PREFIX}/libdata" \
		-DWITH_TESTS:BOOL=OFF
CPE_VENDOR=	eclipse

USERS=		nobody

PLIST_SUB=	DISTVERSION=${DISTVERSION}

OPTIONS_DEFINE=		CARES WEBSOCKETS WEBSOCKETS_BUILTIN
OPTIONS_DEFAULT=	CARES WEBSOCKETS WEBSOCKETS_BUILTIN

CARES_LIB_DEPENDS=	libcares.so:dns/c-ares
CARES_CMAKE_ON=		-DWITH_SRV:BOOL=ON

WEBSOCKETS_DESC=		$(WEBSOCKET_DESC)
WEBSOCKETS_CMAKE_OFF=		-DWITH_WEBSOCKETS:BOOL=OFF
WEBSOCKETS_BUILTIN_CMAKE_OFF=	-DWITH_WEBSOCKETS_BUILTIN:BOOL=OFF
WEBSOCKETS_BUILTIN_DESC=	Use bundled version of websockets

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWEBSOCKETS} && !${PORT_OPTIONS:MWEBSOCKETS_BUILTIN}
LIB_DEPENDS+=	libwebsockets.so:net/libwebsockets
.endif

post-patch:
	@${REINPLACE_CMD} -e '/ldconfig/d' ${WRKSRC}/src/CMakeLists.txt \
		${WRKSRC}/lib/CMakeLists.txt ${WRKSRC}/lib/cpp/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/CMakeLists.txt

post-install:
.for F in mosquitto.conf pwfile pskfile aclfile
	${MV} ${STAGEDIR}${ETCDIR}/${F}.example \
		${STAGEDIR}${ETCDIR}/${F}.sample
.endfor

.include <bsd.port.mk>
