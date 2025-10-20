PORTNAME=	domoticz
DISTVERSION=	2024.7
PORTREVISION=	4
CATEGORIES=	www

MAINTAINER=	kiwi@FreeBSD.org
COMMENT=	Home Automation System
WWW=		https://www.domoticz.com

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/License.txt

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libboost_thread.so:devel/boost-libs \
		libjsoncpp.so:devel/jsoncpp \
		libmosquitto.so:net/mosquitto

USES=		cmake compiler:c++11-lang cpe minizip pkgconfig ssl lua:53 sqlite
USE_GITHUB=	yes
USE_RC_SUBR=	domoticz

CMAKE_OFF+=	GIT_SUBMODULE \
		USE_STATIC_BOOST \
		USE_OPENSSL_STATIC \
		USE_STATIC_BOOST \
		USE_BUILTIN_SQLITE \
		USE_BUILTIN_MINIZIP \
		USE_BUILTIN_JSONCPP \
		USE_BUILTIN_MQTT \
		USE_STATIC_OPENZWAVE

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

PYTHON_USES=		python:3.9+
PYTHON_CMAKE_BOOL=	USE_PYTHON

post-patch:
	@${REINPLACE_CMD} -e '/find_package/s| system||' \
			  -e '/target_link_libraries/s| Boost::system||' \
		${WRKSRC}/CMakeLists.txt

post-install:
	${MKDIR} ${STAGEDIR}/var/db/domoticz ${STAGEDIR}/var/run/domoticz

.include <bsd.port.mk>
