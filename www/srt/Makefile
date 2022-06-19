PORTNAME=	srt
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Secure Reliable Transport (SRT) Protocol

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		cmake:testing compiler:c++11-lang shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	Haivision

SHEBANG_FILES=	scripts/srt-ffplay

CMAKE_TESTING_ON=	ENABLE_TESTING ENABLE_UNITTESTS # 2 tests are known to fail: https://github.com/Haivision/srt/issues/2389, https://github.com/Haivision/srt/issues/2390

OPTIONS_DEFINE=			HEAVY_LOGGING
OPTIONS_RADIO=			ENCRYPTION
OPTIONS_RADIO_ENCRYPTION=	NO_ENCRYPTION OPENSSL GNUTLS MBEDTLS
OPTIONS_DEFAULT=		OPENSSL

HEAVY_LOGGING_DESC=		Enable heavy logging (only for debugging)
HEAVY_LOGGING_CMAKE_BOOL=	ENABLE_HEAVY_LOGGING # may also need srt_setloglevel(LOG_DEBUG) in/after srt_startup() call

NO_ENCRYPTION_DESC=		No encryption
NO_ENCRYPTION_CMAKE_ON=		-DENABLE_ENCRYPTION=OFF

OPENSSL_CMAKE_ON=		-DUSE_ENCLIB=openssl
OPENSSL_USES=			ssl

GNUTLS_CMAKE_ON=		-DUSE_ENCLIB=gnutls
GNUTLS_LIB_DEPENDS=		libgnutls.so:security/gnutls \
				libnettle.so:security/nettle

MBEDTLS_CMAKE_ON=		-DUSE_ENCLIB=mbedtls
MBEDTLS_LIB_DEPENDS=		libmbedtls.so:security/mbedtls

post-install-OPENSSL-on:
	# fix .pc files
	@${REINPLACE_CMD} -e 's|Requires.private: openssl libcrypto|Requires.private:|; s|Libs.private:.*|& -lssl -lcrypto|' \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/srt.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/haisrt.pc

.include <bsd.port.mk>
