PORTNAME=	srt
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.5
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Secure Reliable Transport (SRT) Protocol
WWW=		https://www.srtalliance.org/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash
TEST_DEPENDS=	googletest>=0:devel/googletest

USES=		cmake:testing compiler:c++17-lang pathfix shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	Haivision

SHEBANG_FILES=	scripts/srt-ffplay

CMAKE_TESTING_ON=	ENABLE_TESTING \
			ENABLE_UNITTESTS
CMAKE_TESTING_JOBS=	1

CMAKE_OFF=		CMAKE_CXX_EXTENSIONS \
			ENABLE_STATIC
CMAKE_ON=		ENABLE_SHOW_PROJECT_CONFIG
.if defined(WITH_DEBUG)
CMAKE_ON+=		ENABLE_DEBUG
.endif
.if make(test)
CMAKE_ARGS=		-DUSE_CXX_STD=c++17
.endif

OPTIONS_RADIO=		CRYPTO
OPTIONS_RADIO_CRYPTO=	GNUTLS OPENSSL
OPTIONS_DEFAULT=	OPENSSL

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls \
			libnettle.so:security/nettle
GNUTLS_CMAKE_ON=	-DUSE_ENCLIB=gnutls

OPENSSL_USES=		ssl
OPENSSL_CMAKE_ON=	-DUSE_ENCLIB=openssl

.include <bsd.port.mk>
