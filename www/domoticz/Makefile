# $FreeBSD$

PORTNAME=	domoticz
PORTVERSION=	4.${DOMOTICZ_REL}
PORTREVISION=	3
CATEGORIES=	www

MAINTAINER=	kiwi@oav.net
COMMENT=	Home Automation System

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/License.txt

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2

CONFLICTS_INSTALL?=	domoticz-[23]* domoticz-devel-*

OPTIONS_SUB=	YES
OPTIONS_DEFINE=	PYTHON SBOOST SLUA SMINIZIP SMQTT SSQLITE SSSL TELLDUS
SBOOST_DESC=	Use static Boost instead of dynamic linking
SSSL_DESC=	Use static OpenSSL library instead of dynamic linking
SLUA_DESC=	Use domoticz provided LUA instead of ports one
SMQTT_DESC=	Use domoticz mosquitto instead of ports one
SSQLITE_DESC=	Use domoticz SQLLite instead of ports one
SMINIZIP_DESC=	Use domoticz minizip instead of ports one
PYTHON_DESC=	Enable support for Python Plugins
TELLDUS_DESC=	Enable support for Telldus

.include <bsd.port.options.mk>

USES=		cmake compiler:c++11-lang iconv pkgconfig ssl

# This hack is to get rid of dependency of git while building
# the package.
DOMOTICZ_REL=	9700
DOMOTICZ_TS=	1529904511
USE_GITHUB=	yes
GH_ACCOUNT=	domoticz
GH_PROJECT=	domoticz

USE_RC_SUBR=	domoticz

USERS=		domoticz
GROUPS=		domoticz

CMAKE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}/domoticz \
		-DUSE_BUILTIN_ZLIB="NO" \
		-DUSE_STATIC_OPENZWAVE="NO"

.if ${PORT_OPTIONS:MSSSL}
CMAKE_ARGS+=	-DUSE_OPENSSL_STATIC="YES"
.else
CMAKE_ARGS+=	-DUSE_OPENSSL_STATIC="NO"
.endif

.if ${PORT_OPTIONS:MSBOOST}
CMAKE_ARGS+=	-DUSE_STATIC_BOOST="YES"
BUILD_DEPENDS+=	boost-libs>=0:devel/boost-libs
.else
CMAKE_ARGS+=	-DUSE_STATIC_BOOST="NO"
LIB_DEPENDS+=	libboost_system.so:devel/boost-libs
.endif

.if ${PORT_OPTIONS:MSLUA}
CMAKE_ARGS+=	-DUSE_BUILTIN_LUA="YES"
.else
CMAKE_ARGS+=	-DUSE_BUILTIN_LUA="NO"
USES+=		lua:52
.endif

.if ${PORT_OPTIONS:MSMQTT}
CMAKE_ARGS+=	-DUSE_BUILTIN_MQTT="YES"
.else
CMAKE_ARGS+=	-DUSE_BUILTIN_MQTT="NO"
LIB_DEPENDS+=	libmosquitto.so:net/mosquitto
.endif

.if ${PORT_OPTIONS:MSSQLITE}
CMAKE_ARGS+=	-DUSE_BUILTIN_SQLITE="YES"
.else
CMAKE_ARGS+=	-DUSE_BUILTIN_SQLITE="NO"
USES+=		sqlite
.endif

.if ${PORT_OPTIONS:MSMINIZIP}
CMAKE_ARGS+=	-DUSE_BUILTIN_MINIZIP="YES"
.else
CMAKE_ARGS+=	-DUSE_BUILTIN_MINIZIP="NO"
LIB_DEPENDS+=	libminizip.so:archivers/minizip
.endif

.if ${PORT_OPTIONS:MPYTHON}
CMAKE_ARGS+=	-DUSE_PYTHON="YES"
USES+=		python:3.4
.else
CMAKE_ARGS+=	-DUSE_PYTHON="NO"
.endif

.if ${PORT_OPTIONS:MTELLDUS}
LIB_DEPENDS+=	libtelldus-core.so:comms/telldus-core
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,\/opt,${PREFIX},g" ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e "/^ADD_PRECOMPILED_HEADER/ d" ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e "s/\(#define APPVERSION\)\(.*\)/\1 ${DOMOTICZ_REL}/" ${WRKSRC}/appversion.default
	@${REINPLACE_CMD} -e "s/\(#define APPHASH\)\(.*\)/\1 \"27772d9f\"/" ${WRKSRC}/appversion.default
	@${REINPLACE_CMD} -e "s/\(#define APPDATE\)\(.*\)/\1 ${DOMOTICZ_TS}/" ${WRKSRC}/appversion.default

post-install:
	@${MKDIR} ${STAGEDIR}/var/db/domoticz ${STAGEDIR}/var/run/domoticz

.include <bsd.port.mk>
