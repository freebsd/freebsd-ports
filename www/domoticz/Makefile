PORTNAME=	domoticz
DISTVERSION=	2026.4
PORTREVISION=	0
CATEGORIES=	www

MAINTAINER=	kiwi@FreeBSD.org
COMMENT=	Home Automation System
WWW=		https://www.domoticz.com

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/License.txt

BUILD_DEPENDS=	${LOCALBASE}/include/jwt-cpp/jwt.h:devel/jwt-cpp

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libboost_thread.so:devel/boost-libs \
		libjsoncpp.so:devel/jsoncpp \
		libmosquitto.so:net/mosquitto

USES=		cmake compiler:c++11-lang cpe minizip pkgconfig ssl lua:53 sqlite ssl
USE_GITHUB=	yes
GH_SUBDIR=      extern/libwebem:libwebem
GH_TUPLE=       domoticz:libwebem:dde28f2:libwebem
USE_RC_SUBR=	domoticz

CMAKE_OFF+=	GIT_SUBMODULE \
		USE_STATIC_BOOST \
		USE_OPENSSL_STATIC \
		USE_STATIC_BOOST \
		USE_BUILTIN_SQLITE \
		USE_BUILTIN_MINIZIP \
		USE_BUILTIN_JSONCPP \
		USE_BUILTIN_MQTT \
		USE_STATIC_OPENZWAVE \
		USE_BUILTIN_JWTCPP

CMAKE_INSTALL_PREFIX=	${PREFIX}/domoticz

CONFLICTS_INSTALL=	domoticz-devel-[234]*

EXTRACT_AFTER_ARGS=	--exclude ${PORTNAME}-${PORTVERSION}/hardware/plugins/Include \
			--no-same-owner --no-same-permissions

USERS=		domoticz
GROUPS=		domoticz

OPTIONS_DEFINE=		PRECOMP PYTHON
OPTIONS_DEFAULT=	PRECOMP PYTHON
OPTIONS_SUB=	YES

PRECOMP_DESC=	Enable usage of precompiled header to speed build time
PYTHON_DESC=	Enable Python for Plugins and Event-Scripts

PRECOMP_CMAKE_BOOL=	USE_PRECOMPILED_HEADER

PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	USE_PYTHON

DOMOTICZ_REL=	0
DOMOTICZ_TAG=	78ec238
DOMOTICZ_TS=	0

post-patch:
	@${REINPLACE_CMD} -e "s,\/opt,${PREFIX},g" ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e "s,XXXPREFIXXXX,${PREFIX}/domoticz,g" ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e "/^ADD_PRECOMPILED_HEADER/ d" ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e "s/\(#define APPVERSION\)\(.*\)/\1 ${DOMOTICZ_REL}/" ${WRKSRC}/appversion.h
	@${REINPLACE_CMD} -e "s/\(#define APPHASH\)\(.*\)/\1 \"${DOMOTICZ_TAG}\"/" ${WRKSRC}/appversion.h
	@${REINPLACE_CMD} -e "s/\(#define APPDATE\)\(.*\)/\1 ${DOMOTICZ_TS}/" ${WRKSRC}/appversion.h

post-install:
	${MKDIR} ${STAGEDIR}/var/db/domoticz ${STAGEDIR}/var/run/domoticz

.include <bsd.port.mk>
