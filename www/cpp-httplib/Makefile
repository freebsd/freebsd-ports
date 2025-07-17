PORTNAME=	cpp-httplib
DISTVERSIONPREFIX=	v
DISTVERSION=	0.23.1
CATEGORIES=	www devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only HTTP/HTTPS server and client library
WWW=		https://github.com/yhirose/cpp-httplib

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_13=	configure fails: OpenSSL is too old: Found unsuitable version "1.1.1t", but required is at least "3.0.0"

TEST_DEPENDS=	gmake:devel/gmake

USES=		cmake localbase:ldflags python:test # localbase only for tests

USE_GITHUB=	yes
GH_ACCOUNT=	yhirose

CMAKE_ON=	HTTPLIB_REQUIRE_ZLIB

NO_ARCH=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD} # only for tests

PLIST_FILES=	include/httplib.h \
		lib/cmake/httplib/FindBrotli.cmake \
		share/doc/httplib/README.md \
		lib/cmake/httplib/httplibConfig.cmake \
		lib/cmake/httplib/httplibConfigVersion.cmake \
		lib/cmake/httplib/httplibTargets.cmake

CONFLICTS_BUILD=	googletest # should be CONFLICTS_TEST

OPTIONS_DEFINE=		BROTLI SSL
OPTIONS_DEFAULT=	BROTLI SSL

BROTLI_CMAKE_BOOL=	HTTPLIB_REQUIRE_BROTLI HTTPLIB_USE_BROTLI_IF_AVAILABLE
BROTLI_BUILD_DEPENDS=	brotli>0:archivers/brotli
BROTLI_RUN_DEPENDS=	brotli>0:archivers/brotli

SSL_USES=		ssl
SSL_CMAKE_BOOL=		HTTPLIB_REQUIRE_OPENSSL HTTPLIB_USE_OPENSSL_IF_AVAILABLE

do-test:
	@cd ${WRKSRC}/test && ${SETENV} ${MAKE_ENV} ${GMAKE} CXXFLAGS="${CXXFLAGS} -I${WRKSRC}/test" LDFLAGS="${LDFLAGS}"

# tests as of 0.18.6:
# [  FAILED  ] 1 test, listed below:
# [  FAILED  ] SpecifyServerIPAddressTest.RealHostname_Online


.include <bsd.port.mk>
