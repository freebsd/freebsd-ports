PORTNAME=	mbedtls
DISTVERSION=	2.28.9
CATEGORIES=	security devel
MASTER_SITES=	https://github.com/Mbed-TLS/${PORTNAME}/releases/download/${DISTNAME}/

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	SSL/TLS and cryptography library
WWW=		https://www.trustedfirmware.org/projects/mbed-tls/

LICENSE=	APACHE20 GPLv2+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Upstream support ends at the end of 2024
EXPIRATION_DATE=	2024-12-31

USES=		cmake:testing pathfix python:build,test shebangfix tar:bz2
USE_LDCONFIG=	yes

SHEBANG_FILES=	scripts/*.py tests/scripts/*.py

CMAKE_ON=	CMAKE_BUILD_RPATH_USE_ORIGIN \
		ENABLE_PROGRAMS \
		ENABLE_ZLIB_SUPPORT \
		LINK_WITH_PTHREAD \
		USE_SHARED_MBEDTLS_LIBRARY
CMAKE_OFF=	ENABLE_TESTING
CMAKE_TESTING_ON=	ENABLE_TESTING
CMAKE_TESTING_PARALLEL_LEVEL=	1

PORTSCOUT=	limit:^${DISTVERSION:R:S/./\./g}\.

PLIST_SUB=	DISTVERSION=${DISTVERSION}

pre-configure:
	@${WRKSRC}/scripts/config.py -f ${WRKSRC}/include/mbedtls/config.h set MBEDTLS_SSL_DTLS_SRTP
	@${WRKSRC}/scripts/config.py -f ${WRKSRC}/include/mbedtls/config.h set MBEDTLS_THREADING_C
	@${WRKSRC}/scripts/config.py -f ${WRKSRC}/include/mbedtls/config.h set MBEDTLS_THREADING_PTHREAD

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/include/everest
	@cd ${STAGEDIR}${PREFIX}/bin && for f in *; do \
		${MV} "$$f" "mbedtls_$$f"; \
	done

.include <bsd.port.mk>
