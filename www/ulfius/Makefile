PORTNAME=	ulfius
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.10
CATEGORIES=	www

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Web Framework to build REST APIs, Webservices in C

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libmicrohttpd>0:www/libmicrohttpd \
		yder>0:devel/yder \
		orcania>0:devel/orcania

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libjansson.so:devel/jansson \
		libcurl.so:ftp/curl

RUN_DEPENDS=	jansson>0:devel/jansson \
		gnutls>0:security/gnutls \
		libmicrohttpd>0:www/libmicrohttpd

USES=		cmake cpe

USE_GITHUB=	yes
GH_ACCOUNT=	babelouest

CPE_VENDOR=	ulfius_project
CMAKE_ARGS=	-DWITH_JOURNALD=off \
		-DDOWNLOAD_DEPENDENCIES=off

PLIST_SUB=	PORTVERSION=${PORTVERSION}

MAKE_ENV+=	MAN1=uwsc.1

.include <bsd.port.mk>
