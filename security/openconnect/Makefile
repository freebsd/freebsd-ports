PORTNAME=	openconnect
DISTVERSION=	9.21
CATEGORIES=	security net-vpn
MASTER_SITES=	ftp://ftp.infradead.org/pub/openconnect/ \
		ZI

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Client for Cisco's AnyConnect SSL VPN
WWW=		https://www.infradead.org/openconnect/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

RUN_DEPENDS=	vpnc-script:sysutils/vpnc-scripts

USES=		cpe gmake gnome iconv libtool localbase pkgconfig python:build ssl \
		shebangfix
CPE_VENDOR=	infradead
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
SHEBANG_FILES=	trojans/csd-post.sh trojans/csd-wrapper.sh \
		trojans/tncc-emulate.py \
		trojans/hipreport-android.sh trojans/tncc-wrapper.py
SHEBANG_LANG+=	SH
SH_OLD_CMD+=	/system/bin/sh

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls --with-vpnc-script=${LOCALBASE}/sbin/vpnc-script \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--without-openssl-version-check --without-libpcsclite \
		--without-libpskc
INSTALL_TARGET=	install-strip

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS GNUTLS GSSAPI LZ4 P11KIT P11 PROXY STOKEN
OPTIONS_DEFAULT=GSSAPI

GNUTLS_DESC=		Use GnuTLS instead of OpenSSL (experimental)
LZ4_DESC=		LZ4-based compression
P11KIT_DESC=		PKCS \#11 support via p11-kit
P11_DESC=		PKCS \#11 support via libp11
PROXY_DESC=		Automatic proxy configuration via libproxy
STOKEN_DESC=		With RSA soft token support via libstoken

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_WITH=	gnutls

GSSAPI_CONFIGURE_WITH=	gssapi

LZ4_LIB_DEPENDS=	liblz4.so:archivers/liblz4
LZ4_CONFIGURE_WITH=	lz4

P11KIT_LIB_DEPENDS=	libp11-kit.so:security/p11-kit

P11_LIB_DEPENDS=	libp11.so:security/libp11

PROXY_LIB_DEPENDS=	libproxy.so:net/libproxy
PROXY_CONFIGURE_WITH=	libproxy

STOKEN_LIB_DEPENDS=	libstoken.so:security/stoken \
			libtomcrypt.so:security/libtomcrypt
STOKEN_CONFIGURE_WITH=	stoken

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
