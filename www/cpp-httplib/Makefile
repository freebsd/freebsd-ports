# $FreeBSD$

PORTNAME=	cpp-httplib
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.3
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

OSVERSION!=	awk '/^\#define[[:blank:]]__FreeBSD_version/ {print $$3}' < ${CROSS_SYSROOT}/usr/include/sys/param.h # needed for options, so including bsd.port.options.mk is impossible

OPTIONS_DEFINE=		BROTLI
OPTIONS_DEFAULT=	BROTLI
.if ${OSVERSION} >= 1200000
OPTIONS_DEFINE+=	SSL # fails on 11: Found unsuitable version "1.0.2u", but required is at least "1.1.1"
OPTIONS_DEFAULT+=	SSL
.endif

BROTLI_CMAKE_BOOL=	HTTPLIB_REQUIRE_BROTLI HTTPLIB_USE_BROTLI_IF_AVAILABLE
BROTLI_BUILD_DEPENDS=	brotli>0:archivers/brotli
BROTLI_RUN_DEPENDS=	brotli>0:archivers/brotli

.if ${OSVERSION} >= 1200000
SSL_USES=		ssl
SSL_CMAKE_BOOL=		HTTPLIB_REQUIRE_OPENSSL HTTPLIB_USE_OPENSSL_IF_AVAILABLE
.endif

.include <bsd.port.mk>
