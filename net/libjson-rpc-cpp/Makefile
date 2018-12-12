# $FreeBSD$

PORTNAME=		libjson-rpc-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=		1.1.0
CATEGORIES=		net www devel

MAINTAINER=	greg@unrelenting.technology
COMMENT=	C++ framework for JSON-RPC 1.0 and 2.0

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libmicrohttpd.so:www/libmicrohttpd \
		libjsoncpp.so:devel/jsoncpp \
		libargtable2.so:devel/argtable

USES=		cmake:outsource pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	cinemast

CMAKE_OFF=	COMPILE_TESTS COMPILE_EXAMPLES
CMAKE_ON=	UNIX_DOMAIN_SOCKET_SERVER UNIX_DOMAIN_SOCKET_CLIENT \
		FILE_DESCRIPTOR_SERVER FILE_DESCRIPTOR_CLIENT

OPTIONS_DEFINE=	REDIS
OPTIONS_SUB=	yes

REDIS_CMAKE_BOOL=	REDIS_SERVER REDIS_CLIENT
REDIS_LIB_DEPENDS=	libhiredis.so:databases/hiredis

.include <bsd.port.mk>
