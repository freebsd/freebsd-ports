PORTNAME=	mbedtls
DISTVERSION=	4.2.0
CATEGORIES=	security devel
MASTER_SITES=	https://github.com/Mbed-TLS/${PORTNAME}/releases/download/${DISTNAME}/
PKGNAMESUFFIX=	${DISTVERSION:R:R}

MAINTAINER=	pkaipila@gmail.com
COMMENT=	Embedded SSL/TLS and cryptography library
WWW=		https://www.trustedfirmware.org/projects/mbed-tls/

LICENSE=	APACHE20 GPLv2+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing cpe python:build,test shebangfix tar:bz2
USE_LDCONFIG=	yes

CPE_VENDOR=	trustedfirmware
CPE_PRODUCT=	mbed_tls

SHEBANG_FILES=	scripts/*.py tests/scripts/*.py

CMAKE_ON=	CMAKE_BUILD_RPATH_USE_ORIGIN \
		ENABLE_PROGRAMS \
		LINK_WITH_PTHREAD \
		USE_SHARED_MBEDTLS_LIBRARY
CMAKE_OFF=	ENABLE_TESTING
CMAKE_TESTING_ON=	ENABLE_TESTING
CMAKE_TESTING_JOBS=	1

CONFLICTS_INSTALL=	mbedtls3

PORTSCOUT=	limit:^${DISTVERSION:R:R:S/./\./g}\.

PLIST_SUB=	DISTVERSION=${DISTVERSION}

OPTIONS_DEFINE=	DEBUG

pre-configure:
	@${WRKSRC}/scripts/config.py set MBEDTLS_SSL_DTLS_SRTP
	@${WRKSRC}/scripts/config.py set MBEDTLS_THREADING_C
	@${WRKSRC}/scripts/config.py set MBEDTLS_THREADING_PTHREAD

pre-configure-DEBUG-on:
	@${WRKSRC}/scripts/config.py set MBEDTLS_DEBUG_C

post-install:
	@cd ${STAGEDIR}${PREFIX}/bin && for f in *; do \
		${MV} "$$f" "mbedtls_$$f"; \
	done

post-install-DEBUG-off:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmbedcrypto.so

.include <bsd.port.mk>
