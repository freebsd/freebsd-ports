PORTNAME=	ulfius
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.3
CATEGORIES=	www

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Web Framework to build REST APIs, Webservices in C

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	babelouest

BUILD_DEPENDS+=	libmicrohttpd>0:www/libmicrohttpd
BUILD_DEPENDS+=	yder>0:devel/yder

LIB_DEPENDS+=	libgnutls.so:security/gnutls
LIB_DEPENDS+=	libjansson.so:devel/jansson
LIB_DEPENDS+=	libcurl.so:ftp/curl
BUILD_DEPENDS+=	orcania>0:devel/orcania

RUN_DEPENDS+=	jansson>0:devel/jansson
RUN_DEPENDS+=	gnutls>0:security/gnutls
RUN_DEPENDS+=	libmicrohttpd>0:www/libmicrohttpd

CMAKE_ARGS=	-DWITH_JOURNALD=off

.include <bsd.port.mk>
