PORTNAME=	mosquitto
DISTVERSION=	2.1.2
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	https://mosquitto.org/files/source/

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Open source MQTT broker
WWW=		https://mosquitto.org/

LICENSE=	EPL

BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
		uthash>0:devel/uthash \
		xsltproc:textproc/libxslt
LIB_DEPENDS=	libcjson.so:devel/libcjson \
		libwebsockets.so:net/libwebsockets
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		cmake cpe libedit localbase:ldflags ssl sqlite
CPE_VENDOR=	eclipse
USE_LDCONFIG=	yes

USE_RC_SUBR=	mosquitto

USERS=		nobody

PLIST_SUB=	DISTVERSION=${DISTVERSION}

CMAKE_OFF=	WITH_BUNDLED_DEPS \
		WITH_HTTP_API \
		WITH_TESTS \
		WITH_WEBSOCKETS_BUILTIN

OPTIONS_DEFINE=		CARES
OPTIONS_DEFAULT=	CARES

CARES_LIB_DEPENDS=	libcares.so:dns/c-ares
CARES_CMAKE_BOOL=	WITH_SRV

post-install:
.for F in mosquitto.conf pwfile pskfile aclfile
	${MV} ${STAGEDIR}${ETCDIR}/${F}.example \
		${STAGEDIR}${ETCDIR}/${F}.sample
.endfor

.include <bsd.port.mk>
