PORTNAME=	domoticz
PORTVERSION=	2024.7.${DOMOTICZ_REL}
PORTREVISION=	6
CATEGORIES=	www
PKGNAMESUFFIX=	-devel

MAINTAINER=	kiwi@FreeBSD.org
COMMENT=	Home Automation System (Development Branch)
WWW=		https://www.domoticz.com

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/License.txt

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libboost_thread.so:devel/boost-libs \
		libjsoncpp.so:devel/jsoncpp \
		libmosquitto.so:net/mosquitto

USES=		cmake compiler:c++11-lang cpe lua:53 minizip pkgconfig sqlite \
		ssl

USE_GITHUB=	yes
GH_TAGNAME=	a580a6b1f

CONFLICTS_INSTALL=	domoticz-[234]*

EXTRACT_AFTER_ARGS=	--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/hardware/plugins/Include \
			--no-same-owner --no-same-permissions

# This hack is to get rid of dependency of git while building
# the package.
DOMOTICZ_REL=	16186
DOMOTICZ_TS=	1724156096

USE_RC_SUBR=	domoticz
USERS=		domoticz
GROUPS=		domoticz

CMAKE_INSTALL_PREFIX=   ${PREFIX}/domoticz

CMAKE_OFF=	GIT_SUBMODULE \
		USE_BUILTIN_JSONCPP \
		USE_BUILTIN_MINIZIP \
		USE_BUILTIN_MQTT \
		USE_LUA_STATIC \
		USE_STATIC_BOOST \
		USE_STATIC_OPENZWAVE

OPTIONS_DEFINE=		PRECOMP PYTHON
OPTIONS_DEFAULT=	PRECOMP PYTHON
OPTIONS_SUB=		yes

PRECOMP_DESC=		Enable usage of precompiled header to speed build time
PYTHON_DESC=		Enable support for Python Plugins

PYTHON_USES=		python:3.9+
PYTHON_CMAKE_BOOL=	USE_PYTHON

PRECOMP_CMAKE_BOOL=	USE_PRECOMPILED_HEADER

post-patch:
	@${REINPLACE_CMD} -e '/find_package/s| system||' \
			  -e '/target_link_libraries/s| Boost::system||' \
			  -e "s,\/opt,${PREFIX},g" ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e "s,XXXPREFIXXXX,${PREFIX}/domoticz,g" ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e "/^ADD_PRECOMPILED_HEADER/ d" ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e "s/\(#define APPVERSION\)\(.*\)/\1 ${DOMOTICZ_REL}/" ${WRKSRC}/appversion.h
	@${REINPLACE_CMD} -e "s/\(#define APPHASH\)\(.*\)/\1 \"${GH_TAGNAME}\"/" ${WRKSRC}/appversion.h
	@${REINPLACE_CMD} -e "s/\(#define APPDATE\)\(.*\)/\1 ${DOMOTICZ_TS}/" ${WRKSRC}/appversion.h

post-install:
	${MKDIR} ${STAGEDIR}/var/db/domoticz ${STAGEDIR}/var/run/domoticz

.include <bsd.port.mk>
