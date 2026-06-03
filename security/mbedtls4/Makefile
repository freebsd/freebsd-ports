PORTNAME=	mbedtls
DISTVERSION=	4.1.0
PORTREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	https://github.com/Mbed-TLS/${PORTNAME}/releases/download/${DISTNAME}/
PKGNAMESUFFIX=	4

PATCH_SITES=	https://github.com/Mbed-TLS/${PORTNAME}/commit/
PATCHFILES=	5fc28f401666f3ab3338168f6dcee71e6b468a4e.patch:-p1
# Fix a TLS 1.2 client regression that caused valid ServerKeyExchange
# signatures using rsa_pss_rsae_* to be rejected.
# https://github.com/Mbed-TLS/mbedtls/issues/10668

MAINTAINER=	pkaipila@gmail.com
COMMENT=	Embedded SSL/TLS and cryptography library
WWW=		https://www.trustedfirmware.org/projects/mbed-tls/

LICENSE=	APACHE20 GPLv2+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing python:build,test shebangfix tar:bz2
USE_LDCONFIG=	yes

SHEBANG_FILES=	scripts/*.py tests/scripts/*.py

CMAKE_ON=	CMAKE_BUILD_RPATH_USE_ORIGIN \
		ENABLE_PROGRAMS \
		LINK_WITH_PTHREAD \
		USE_SHARED_MBEDTLS_LIBRARY
CMAKE_OFF=	ENABLE_TESTING
CMAKE_TESTING_ON=	ENABLE_TESTING
CMAKE_TESTING_JOBS=	1

CONFLICTS_INSTALL=	mbedtls3

PORTSCOUT=	limit:^${DISTVERSION:R:S/./\./g}\.

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
