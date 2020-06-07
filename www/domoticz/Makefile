# $FreeBSD$

PORTNAME=	domoticz
PORTVERSION=	2020.2
CATEGORIES=	www

MAINTAINER=	kiwi@oav.net
COMMENT=	Home Automation System

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/License.txt

LIB_DEPENDS=	libcurl.so:ftp/curl libboost_system.so:devel/boost-libs \
		libminizip.so:archivers/minizip libjsoncpp.so:devel/jsoncpp
BUILD_DEPENDS=	cereal>=1.2.2:devel/cereal

USES=		cmake compiler:c++11-lang pkgconfig ssl lua:53 sqlite

OPTIONS_SUB=	YES
OPTIONS_DEFINE=	SMQTT PYTHON TELLDUS OPENZWAVE PRECOMP
OPTIONS_DEFAULT=	PYTHON PRECOMP
SMQTT_DESC=	Use domoticz Mosquitto instead of ports one
PYTHON_DESC=	Enable Python for Plugins and Event-Scripts
TELLDUS_DESC=	Enable Tellstick Telldus support
OPENZWAVE_DESC=	Enable OpenZWave support
PRECOMP_DESC=	Enable usage of precompiled header to speed build time

.include <bsd.port.options.mk>

USE_GITHUB=	yes
# allow to build port with MQQT version recommended by the upstream
# see https://github.com/domoticz/domoticz/tree/development/extern for the
# specific release tag
GH_TUPLE=	eclipse:mosquitto:22e0a4b:mosquitto/extern/mosquitto

USE_RC_SUBR=	domoticz

USERS=		domoticz
GROUPS=		domoticz

CMAKE_INSTALL_PREFIX=	${PREFIX}/domoticz
CMAKE_OFF+=		GIT_SUBMODULE USE_STATIC_BOOST USE_OPENSSL_STATIC \
			USE_BUILTIN_SQLITE USE_BUILTIN_MINIZIP USE_BUILTIN_JSONCPP

.if ${PORT_OPTIONS:MSMQTT}
CMAKE_ON+=	USE_BUILTIN_MQTT
.else
CMAKE_OFF+=	USE_BUILTIN_MQTT
LIB_DEPENDS+=	libmosquitto.so:net/mosquitto
.endif

.if ${PORT_OPTIONS:MPYTHON}
CMAKE_ON+=	USE_PYTHON
USES+=		python:3.7
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

.if ${PORT_OPTIONS:MOPENZWAVE}
CMAKE_OFF+=	USE_STATIC_OPENZWAVE
LIB_DEPENDS+=	libopenzwave.so:comms/openzwave-devel
.endif

post-install:
	${MKDIR} ${STAGEDIR}/var/db/domoticz ${STAGEDIR}/var/run/domoticz

.include <bsd.port.mk>
