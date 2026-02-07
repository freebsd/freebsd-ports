PORTNAME=	openconnect
PORTVERSION=	9.12
PORTREVISION=	2
CATEGORIES=	security net-vpn
MASTER_SITES=	ftp://ftp.infradead.org/pub/openconnect/ \
		ZI

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Client for Cisco's AnyConnect SSL VPN
WWW=		https://www.infradead.org/openconnect/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

RUN_DEPENDS=	vpnc-script:sysutils/vpnc-scripts

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--disable-nls --with-vpnc-script=${LOCALBASE}/sbin/vpnc-script \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--without-openssl-version-check --without-libpcsclite \
		--without-libpskc
USES=		cpe gmake gnome iconv libtool localbase pkgconfig python:build ssl \
		shebangfix
CPE_VENDOR=	infradead
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
SHEBANG_LANG+=	SH
SH_OLD_CMD+=	/system/bin/sh
SHEBANG_FILES=	trojans/csd-post.sh trojans/csd-wrapper.sh \
		trojans/tncc-emulate.py \
		trojans/hipreport-android.sh trojans/tncc-wrapper.py
USE_GNOME=	libxml2
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS PROXY GNUTLS GSSAPI LZ4 P11 STOKEN
OPTIONS_DEFAULT=GSSAPI

LZ4_DESC=		LZ4-based compression
LZ4_LIB_DEPENDS=	liblz4.so:archivers/liblz4
LZ4_CONFIGURE_WITH=	lz4

PROXY_DESC=		Automatic proxy configuration via libproxy
PROXY_LIB_DEPENDS=	libproxy.so:net/libproxy
PROXY_CONFIGURE_WITH=	libproxy

GNUTLS_DESC=		Use GnuTLS instead of OpenSSL (experimental)
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_WITH=	gnutls

GSSAPI_CONFIGURE_WITH=	gssapi

P11_DESC=		PKCS \#11 support via libp11
P11_LIB_DEPENDS=	libp11.so:security/libp11

STOKEN_DESC=		With RSA soft token support via libstoken
STOKEN_LIB_DEPENDS=	libstoken.so:security/stoken \
				libtomcrypt.so:security/libtomcrypt
STOKEN_CONFIGURE_WITH=	stoken

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
