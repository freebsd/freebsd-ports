# $FreeBSD$

PORTNAME=	cpp-httplib
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.5
CATEGORIES=	www devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only HTTP/HTTPS server and client library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	yhirose

CMAKE_ON=	HTTPLIB_REQUIRE_ZLIB

NO_ARCH=	yes

PLIST_FILES=	include/httplib.h \
		lib/cmake/httplib/FindBrotli.cmake \
		lib/cmake/httplib/httplibConfig.cmake \
		lib/cmake/httplib/httplibConfigVersion.cmake \
		lib/cmake/httplib/httplibTargets.cmake

OPTIONS_DEFINE=		BROTLI ${${OSVERSION}>1200085:?SSL:}
OPTIONS_DEFAULT=	BROTLI ${${OSVERSION}>1200085:?SSL:}

BROTLI_CMAKE_BOOL=	HTTPLIB_REQUIRE_BROTLI HTTPLIB_USE_BROTLI_IF_AVAILABLE
BROTLI_BUILD_DEPENDS=	brotli>0:archivers/brotli
BROTLI_RUN_DEPENDS=	brotli>0:archivers/brotli

SSL_USES=		ssl
SSL_CMAKE_BOOL=		HTTPLIB_REQUIRE_OPENSSL HTTPLIB_USE_OPENSSL_IF_AVAILABLE

.include <bsd.port.mk>
