PORTNAME=	mosquitto
DISTVERSION=	2.0.22
CATEGORIES=	net
MASTER_SITES=	https://mosquitto.org/files/source/

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Open source MQTT broker
WWW=		https://mosquitto.org/

LICENSE=	EPL

BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
		xsltproc:textproc/libxslt
LIB_DEPENDS=	libcjson.so:devel/libcjson \
		libuuid.so:misc/libuuid
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		cmake cpe ssl
USE_RC_SUBR=	mosquitto
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DCMAKE_LIBDATADIR:PATH="${PREFIX}/libdata"
CPE_VENDOR=	eclipse

USERS=		nobody

PLIST_SUB=	DISTVERSION=${DISTVERSION}

OPTIONS_DEFINE=		CARES WEBSOCKET
OPTIONS_DEFAULT=	CARES WEBSOCKET

CARES_LIB_DEPENDS=	libcares.so:dns/c-ares
CARES_CMAKE_ON=		-DWITH_SRV:BOOL=ON

WEBSOCKET_LIB_DEPENDS=	libwebsockets.so:net/libwebsockets
WEBSOCKET_CMAKE_ON=	-DWITH_WEBSOCKETS:BOOL=ON

post-patch:
	@${REINPLACE_CMD} -e '/ldconfig/d' ${WRKSRC}/src/CMakeLists.txt \
		${WRKSRC}/lib/CMakeLists.txt ${WRKSRC}/lib/cpp/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/CMakeLists.txt

post-install:
	${SED} -e '/cafile/s,/usr/local,${LOCALBASE},' \
		${STAGEDIR}${ETCDIR}/mosquitto.conf > \
		${STAGEDIR}${ETCDIR}/mosquitto.conf.sample
	${MV} ${STAGEDIR}${ETCDIR}/pwfile.example \
		${STAGEDIR}${ETCDIR}/pwfile.sample
	${MV} ${STAGEDIR}${ETCDIR}/pskfile.example \
		${STAGEDIR}${ETCDIR}/pskfile.sample
	${MV} ${STAGEDIR}${ETCDIR}/aclfile.example \
		${STAGEDIR}${ETCDIR}/aclfile.sample

.include <bsd.port.mk>
