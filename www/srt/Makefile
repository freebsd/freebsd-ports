PORTNAME=	srt
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.4
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Secure Reliable Transport (SRT) Protocol
WWW=		https://www.srtalliance.org/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		cmake compiler:c++11-lang pathfix shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	Haivision

SHEBANG_FILES=	scripts/srt-ffplay

# CMAKE_TESTING_ON=	ENABLE_TESTING \
#			ENABLE_UNITTESTS
# 1 test fails when net.inet6.ip6.v6only=1
# https://github.com/Haivision/srt/issues/2389
# tests fail to compile,
# https://github.com/Haivision/srt/issues/2796
# https://github.com/Haivision/srt/issues/2758

CMAKE_OFF=		CMAKE_CXX_EXTENSIONS \
			ENABLE_STATIC
CMAKE_ON=		ENABLE_SHOW_PROJECT_CONFIG

OPTIONS_DEFINE=		HEAVY_LOGGING
OPTIONS_RADIO=		CRYPTO
OPTIONS_RADIO_CRYPTO=	GNUTLS NONE OPENSSL
OPTIONS_DEFAULT=	OPENSSL

HEAVY_LOGGING_DESC=	Enable heavy logging (only for debugging)
NONE_DESC=		No encryption support

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls \
			libnettle.so:security/nettle
GNUTLS_CMAKE_ON=	-DUSE_ENCLIB=gnutls

HEAVY_LOGGING_CMAKE_BOOL=	ENABLE_HEAVY_LOGGING # may also need srt_setloglevel(LOG_DEBUG) in/after srt_startup() call

NONE_CMAKE_ON=		-DENABLE_ENCRYPTION=OFF

OPENSSL_USES=		ssl
OPENSSL_CMAKE_ON=	-DUSE_ENCLIB=openssl

.include <bsd.port.mk>
