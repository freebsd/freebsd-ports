PORTNAME=	cpp-httplib
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
CATEGORIES=	www devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only HTTP/HTTPS server and client library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	gmake:devel/gmake \
		googletest>0:devel/googletest

USES=		cmake localbase:ldflags python:test # localbase only for tests

USE_GITHUB=	yes
GH_ACCOUNT=	yhirose

CMAKE_ON=	HTTPLIB_REQUIRE_ZLIB

NO_ARCH=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD} # only for tests

PLIST_FILES=	include/httplib.h \
		lib/cmake/httplib/FindBrotli.cmake \
		lib/cmake/httplib/httplibConfig.cmake \
		lib/cmake/httplib/httplibConfigVersion.cmake \
		lib/cmake/httplib/httplibTargets.cmake

OPTIONS_DEFINE=		BROTLI SSL
OPTIONS_DEFAULT=	BROTLI SSL

BROTLI_CMAKE_BOOL=	HTTPLIB_REQUIRE_BROTLI HTTPLIB_USE_BROTLI_IF_AVAILABLE
BROTLI_BUILD_DEPENDS=	brotli>0:archivers/brotli
BROTLI_RUN_DEPENDS=	brotli>0:archivers/brotli

SSL_USES=		ssl
SSL_CMAKE_BOOL=		HTTPLIB_REQUIRE_OPENSSL HTTPLIB_USE_OPENSSL_IF_AVAILABLE

do-test: install
	@cd ${WRKSRC}/test && ${SETENV} ${MAKE_ENV} ${GMAKE} CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS}"

.include <bsd.port.mk>
