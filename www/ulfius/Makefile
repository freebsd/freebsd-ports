PORTNAME=	ulfius
PORTVERSION=	2.7.15
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Web Framework to build REST APIs, Webservices or any HTTP endpoint in C
WWW=		https://babelouest.github.io/ulfius/ \
		https://github.com/babelouest/ulfius

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	curl>=7.16.2:ftp/curl \
		gnutls>=3.5.0:security/gnutls \
		jansson>=2.4:devel/jansson \
		libmicrohttpd>=0.9.53:www/libmicrohttpd \
		orcania>=2.3.3:devel/orcania \
		yder>=1.4.20:devel/yder
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libgnutls.so:security/gnutls \
		libjansson.so:devel/jansson \
		libmicrohttpd.so:www/libmicrohttpd \
		liborcania.so:devel/orcania \
		libyder.so:devel/yder

USES=		cmake cpe pathfix

CMAKE_OFF=	BUILD_RPM BUILD_ULFIUS_DOCUMENTATION BUILD_ULFIUS_TESTING
CMAKE_ON=	BUILD_SHARED BUILD_STATIC BUILD_UWSC INSTALL_HEADER SEARCH_ORCANIA_U SEARCH_YDER WITH_CURL WITH_GNUTLS WITH_JANSSON WITH_WEBSOCKET WITH_WEBSOCKET_MESSAGE_LIST WITH_YDER
MAKE_ENV=	MAN1=uwsc.1

PLIST_SUB=	PORTVERSION=${PORTVERSION}

CPE_VENDOR=	ulfius_project

USE_GITHUB=	yes
GH_ACCOUNT=	babelouest

.include <bsd.port.mk>
