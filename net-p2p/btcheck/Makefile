# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	btcheck
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	BitTorrent data checker and torrent file content viewer

LICENSE=	GPLv3

GNU_CONFIGURE=	yes

CONFLICTS_INSTALL=	libbt # bin/btcheck

PLIST_FILES=	bin/btcheck man/man1/btcheck.1.gz
PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS
OPTIONS_RADIO=	SHA1
SHA1_DESC=	Optimized SHA-1 calculation
OPTIONS_RADIO_SHA1=	BEECRYPT GCRYPT GNUTLS MBEDTLS NETTLE OPENSSL TOMCRYPT
OPTIONS_DEFAULT=	OPENSSL

BEECRYPT_DESC=		Use SHA-1 implementation from BeeCrypt
BEECRYPT_LIB_DEPENDS=	libbeecrypt.so:security/beecrypt
BEECRYPT_USES=		localbase
BEECRYPT_CONFIGURE_ON=	--with-beecrypt

GCRYPT_DESC=		Use SHA-1 implementation from GNU crypt
GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt
GCRYPT_USES=		localbase
GCRYPT_CONFIGURE_ON=	--with-gcrypt

GNUTLS_DESC=		Use SHA-1 implementation from GnuTLS
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_USES=		localbase
GNUTLS_CONFIGURE_ON=	--with-gnutls

MBEDTLS_DESC=		Use SHA-1 implementation from mbedTLS/PolarSSL
MBEDTLS_LIB_DEPENDS=	libmbedcrypto.so:security/mbedtls
MBEDTLS_USES=		localbase
MBEDTLS_CONFIGURE_ON=	--with-polarssl

NETTLE_DESC=		Use SHA-1 implementation from Nettle
NETTLE_LIB_DEPENDS=	libnettle.so:security/nettle
NETTLE_USES=		localbase
NETTLE_CONFIGURE_ON=	--with-nettle

OPENSSL_DESC=		Use SHA-1 implementation from OpenSSL
OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_ON=	--with-openssl

TOMCRYPT_DESC=		Use SHA-1 implementation from LibTomCrypt
TOMCRYPT_LIB_DEPENDS=	libtomcrypt.so:security/libtomcrypt
TOMCRYPT_USES=		localbase
TOMCRYPT_CONFIGURE_ON=	--with-tomcrypt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
