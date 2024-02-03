PORTNAME=	mbedtls
DISTVERSIONPREFIX=${PORTNAME}-
DISTVERSION=	2.28.7
CATEGORIES=	security devel

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	SSL/TLS and cryptography library
WWW=		https://www.trustedfirmware.org/projects/mbed-tls/

LICENSE=	APACHE20 GPLv2+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing python:build,test shebangfix
SHEBANG_FILES=	scripts/*.py tests/scripts/*.py
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Mbed-TLS

PORTSCOUT=	limit:^${DISTVERSION:R:S/./\./g}\.
PLIST_SUB=	DISTVERSION=${DISTVERSION}

CMAKE_TESTING_ON=	ENABLE_TESTING

CMAKE_OFF=	ENABLE_TESTING
CMAKE_ON=	CMAKE_BUILD_RPATH_USE_ORIGIN \
		ENABLE_PROGRAMS \
		ENABLE_ZLIB_SUPPORT \
		LINK_WITH_PTHREAD \
		USE_SHARED_MBEDTLS_LIBRARY

pre-configure:
	@${WRKSRC}/scripts/config.py -f ${WRKSRC}/include/mbedtls/config.h set MBEDTLS_SSL_DTLS_SRTP
	@${WRKSRC}/scripts/config.py -f ${WRKSRC}/include/mbedtls/config.h set MBEDTLS_THREADING_C
	@${WRKSRC}/scripts/config.py -f ${WRKSRC}/include/mbedtls/config.h set MBEDTLS_THREADING_PTHREAD

post-install:
	@cd ${STAGEDIR}${PREFIX}/bin && for f in *; do \
		${MV} "$$f" "mbedtls_$$f"; \
	done

.include <bsd.port.mk>
