PORTNAME=	domoticz
DISTVERSION=	2025.2.${DOMOTICZ_REL}
CATEGORIES=	www
PKGNAMESUFFIX=	-devel

MAINTAINER=	kiwi@FreeBSD.org
COMMENT=	Home Automation System (Development Branch)
WWW=		https://www.domoticz.com

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/License.txt

BUILD_DEPENDS=	${LOCALBASE}/include/jwt-cpp/jwt.h:devel/jwt-cpp

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libboost_thread.so:devel/boost-libs \
		libjsoncpp.so:devel/jsoncpp \
		libmosquitto.so:net/mosquitto

USES=		cmake compiler:c++11-lang cpe lua:53 minizip pkgconfig sqlite \
		ssl

USE_GITHUB=	yes
GH_TAGNAME=	32b88a6aa
USE_RC_SUBR=	domoticz

CMAKE_OFF=	GIT_SUBMODULE \
		USE_BUILTIN_JSONCPP \
		USE_BUILTIN_MINIZIP \
		USE_BUILTIN_MQTT \
		USE_LUA_STATIC \
		USE_STATIC_BOOST \
		USE_STATIC_OPENZWAVE \
		USE_BUILTIN_JWTCPP

CMAKE_INSTALL_PREFIX=   ${PREFIX}/domoticz

CONFLICTS_INSTALL=	domoticz-[234]*

EXTRACT_AFTER_ARGS=	--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/hardware/plugins/Include \
			--no-same-owner --no-same-permissions

# This hack is to get rid of dependency of git while building
# the package.
DOMOTICZ_REL=	16884
DOMOTICZ_TS=	1762861862

USERS=		domoticz
GROUPS=		domoticz

OPTIONS_DEFINE=		PRECOMP PYTHON
OPTIONS_DEFAULT=	PRECOMP PYTHON
OPTIONS_SUB=		yes

PRECOMP_DESC=		Enable usage of precompiled header to speed build time
PYTHON_DESC=		Enable support for Python Plugins

PRECOMP_CMAKE_BOOL=	USE_PRECOMPILED_HEADER

PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	USE_PYTHON

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
