PORTNAME=	sngrep
DISTVERSION=	1.8.4
CATEGORIES=	net
MASTER_SITES=	https://github.com/irontec/${PORTNAME}/releases/download/v${DISTVERSION}/

PATCH_SITES=	https://github.com/irontec/sngrep/commit/
PATCHFILES=	3553fc8f6afed9d6e985efb34db250ec5b7fa903.patch:-p1

MAINTAINER=	tad@vif.com
COMMENT=	SIP Packet display and capture
WWW=		https://github.com/irontec/sngrep

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake ncurses pkgconfig

TEST_TARGET=	tests

CMAKE_ON=	USE_IPV6 \
		USE_EEP \
		WITH_UNICODE \
		WITH_ZLIB

OPTIONS_DEFINE=		PCRE UNICODE
OPTIONS_DEFAULT=	OPENSSL

OPTIONS_RADIO=		SSL
OPTIONS_RADIO_SSL=	GNUTLS OPENSSL

GNUTLS_USES=		localbase:ldflags
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls \
			libgcrypt.so:security/libgcrypt
GNUTLS_CMAKE_BOOL=	WITH_GNUTLS

OPENSSL_USES=		ssl
OPENSSL_CMAKE_BOOL=	WITH_OPENSSL

PCRE_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
PCRE_CMAKE_BOOL=	WITH_PCRE2

pre-test:
	${CP} ${WRKSRC}/tests/*.pcap ${BUILD_WRKSRC}

post-test:
	@cd ${BUILD_WRKSRC} && for f in test_*; do \
	    ./"$$f"; \
	done

.include <bsd.port.mk>
