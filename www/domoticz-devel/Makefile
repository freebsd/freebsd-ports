PORTNAME=	domoticz
PORTVERSION=	2024.7.${DOMOTICZ_REL}
CATEGORIES=	www
PKGNAMESUFFIX=	-devel

MAINTAINER=	kiwi@oav.net
COMMENT=	Home Automation System (Development Branch)
WWW=		https://www.domoticz.com

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/License.txt

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libboost_system.so:devel/boost-libs \
		libjsoncpp.so:devel/jsoncpp \
		libmosquitto.so:net/mosquitto

USES=		cmake compiler:c++11-lang cpe lua:53 minizip pkgconfig sqlite \
		ssl

CONFLICTS_INSTALL?=	domoticz-[234]*

# Do not extract python Includes
EXTRACT_AFTER_ARGS=	--exclude hardware/plugins/Include

OPTIONS_DEFINE=		PRECOMP PYTHON TELLDUS
OPTIONS_DEFAULT=	PRECOMP PYTHON
OPTIONS_SUB=		YES
PRECOMP_DESC=		Enable usage of precompiled header to speed build time
PYTHON_DESC=		Enable support for Python Plugins
TELLDUS_DESC=		Enable support for Telldus

.include <bsd.port.options.mk>

# This hack is to get rid of dependency of git while building
# the package.
DOMOTICZ_REL=	16186
DOMOTICZ_TS=	1724156096
USE_GITHUB=	yes
GH_TAGNAME=	a580a6b1f

USE_RC_SUBR=	domoticz

USERS=		domoticz
GROUPS=		domoticz

CMAKE_INSTALL_PREFIX=	${PREFIX}/domoticz
CMAKE_OFF+=		GIT_SUBMODULE USE_STATIC_BOOST USE_OPENSSL_STATIC \
			USE_STATIC_BOOST USE_BUILTIN_JSONCPP USE_BUILTIN_MINIZIP \
			USE_BUILTIN_MQTT USE_STATIC_OPENZWAVE USE_BUILTIN_SQLITE \
			USE_LUA_STATIC

.if ${PORT_OPTIONS:MPYTHON}
CMAKE_ON+=	USE_PYTHON
USES+=		python:3.9+
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

post-patch:
	@${REINPLACE_CMD} -e "s,\/opt,${PREFIX},g" ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e "s,XXXPREFIXXXX,${PREFIX}/domoticz,g" ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e "/^ADD_PRECOMPILED_HEADER/ d" ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e "s/\(#define APPVERSION\)\(.*\)/\1 ${DOMOTICZ_REL}/" ${WRKSRC}/appversion.h
	@${REINPLACE_CMD} -e "s/\(#define APPHASH\)\(.*\)/\1 \"${GH_TAGNAME}\"/" ${WRKSRC}/appversion.h
	@${REINPLACE_CMD} -e "s/\(#define APPDATE\)\(.*\)/\1 ${DOMOTICZ_TS}/" ${WRKSRC}/appversion.h

post-install:
	${MKDIR} ${STAGEDIR}/var/db/domoticz ${STAGEDIR}/var/run/domoticz

.include <bsd.port.mk>
