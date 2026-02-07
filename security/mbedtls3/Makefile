PORTNAME=	mbedtls
DISTVERSION=	3.6.5
CATEGORIES=	security devel
MASTER_SITES=	https://github.com/Mbed-TLS/${PORTNAME}/releases/download/${DISTNAME}/
PKGNAMESUFFIX=	3

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	SSL/TLS and cryptography library
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

PORTSCOUT=	limit:^${DISTVERSION:R:S/./\./g}\.

PLIST_SUB=	DISTVERSION=${DISTVERSION}

post-patch:
	@${REINPLACE_CMD} '/(everest)/d;/(p256-m)/d' \
		${WRKSRC}/3rdparty/CMakeLists.txt

pre-configure:
	@${WRKSRC}/scripts/config.py set MBEDTLS_SSL_DTLS_SRTP
	@${WRKSRC}/scripts/config.py set MBEDTLS_THREADING_C
	@${WRKSRC}/scripts/config.py set MBEDTLS_THREADING_PTHREAD

post-install:
	@cd ${STAGEDIR}${PREFIX}/bin && for f in *; do \
		${MV} "$$f" "mbedtls_$$f"; \
	done

.include <bsd.port.mk>
