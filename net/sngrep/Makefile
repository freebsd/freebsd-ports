PORTNAME=	sngrep
DISTVERSION=	1.4.9
CATEGORIES=	net
MASTER_SITES=	https://github.com/irontec/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	tad@vif.com
COMMENT=	SIP Packet display and capture

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf localbase ncurses pkgconfig

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=		EEP IPV6 PCRE UNICODE
OPTIONS_DEFAULT=	EEP IPV6 UNICODE OPENSSL

OPTIONS_RADIO=		SSL
OPTIONS_RADIO_SSL=	GNUTLS OPENSSL

EEP_DESC=		Enable EEP packet send/receive support

EEP_CONFIGURE_ENABLE=	eep
IPV6_CONFIGURE_ENABLE=	ipv6

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls \
			libgcrypt.so:security/libgcrypt \
			libgpg-error.so:security/libgpg-error
GNUTLS_CONFIGURE_WITH=	gnutls

OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_ENV+=	SSL_CFLAGS="-I${OPENSSLINC}" \
			SSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl"
OPENSSL_CONFIGURE_WITH=	openssl

PCRE_CONFIGURE_WITH=	pcre
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre

UNICODE_CONFIGURE_ENABLE=	unicode

.include <bsd.port.mk>
