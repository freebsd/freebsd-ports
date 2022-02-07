PORTNAME=	domoticz
PORTVERSION=	2022.1
CATEGORIES=	www

MAINTAINER=	kiwi@oav.net
COMMENT=	Home Automation System

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/License.txt

LIB_DEPENDS=	libcurl.so:ftp/curl libboost_system.so:devel/boost-libs \
		libjsoncpp.so:comms/openzwave-devel \
		libjsoncpp.so:devel/jsoncpp \
		libmosquitto.so:net/mosquitto

BUILD_DEPENDS=	cereal>=1.2.2:devel/cereal

USES=		cmake compiler:c++11-lang cpe minizip pkgconfig ssl lua:53 sqlite

OPTIONS_SUB=	YES
OPTIONS_DEFINE=	PYTHON TELLDUS PRECOMP
OPTIONS_DEFAULT=	PYTHON PRECOMP
PYTHON_DESC=	Enable Python for Plugins and Event-Scripts
TELLDUS_DESC=	Enable Tellstick Telldus support
PRECOMP_DESC=	Enable usage of precompiled header to speed build time

.include <bsd.port.options.mk>

USE_GITHUB=	yes

USE_RC_SUBR=	domoticz

USERS=		domoticz
GROUPS=		domoticz

CMAKE_INSTALL_PREFIX=	${PREFIX}/domoticz
CMAKE_OFF+=		GIT_SUBMODULE USE_STATIC_BOOST USE_OPENSSL_STATIC \
			USE_BUILTIN_SQLITE USE_BUILTIN_MINIZIP USE_BUILTIN_JSONCPP \
			USE_BUILTIN_MQTT USE_STATIC_OPENZWAVE

.if ${PORT_OPTIONS:MPYTHON}
CMAKE_ON+=	USE_PYTHON
USES+=		python:3.8+
.else
CMAKE_OFF+=	USE_PYTHON
.endif

.if ${PORT_OPTIONS:MTELLDUS}
LIB_DEPENDS+=	libtelldus-core.so:comms/telldus-core
.endif

.if ${PORT_OPTIONS:MPRECOMP}
CMAKE_ON+=	USE_PRECOMPILED_HEADER
.else
CMAKE_OFF+=	USE_PRECOMPILED_HEADER
.endif

post-install:
	${MKDIR} ${STAGEDIR}/var/db/domoticz ${STAGEDIR}/var/run/domoticz

.include <bsd.port.mk>
