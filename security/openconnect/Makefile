# Created by: Damian Gerow <dgerow@afflictions.org>
# $FreeBSD$

PORTNAME=	openconnect
PORTVERSION=	7.08
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.infradead.org/pub/openconnect/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Client for Cisco's AnyConnect SSL VPN

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

LIB_DEPENDS=	libxml2.so:textproc/libxml2
RUN_DEPENDS=	vpnc-script:sysutils/vpnc-scripts

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls --with-vpnc-script=${LOCALBASE}/sbin/vpnc-script \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--without-stoken --without-openssl-version-check
USES=		cpe gmake iconv libtool pkgconfig python:build ssl
CPE_VENDOR=	infradead
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
PORTDOCS=	*

OPTIONS_DEFINE=	PROXY GNUTLS LZ4 P11

LZ4_DESC=		LZ4-based compression
LZ4_LIB_DEPENDS=	liblz4.so:archivers/liblz4
LZ4_CONFIGURE_WITH=	lz4

PROXY_DESC=		Automatic proxy configuration via libproxy
PROXY_LIB_DEPENDS=	libproxy.so:net/libproxy
PROXY_CONFIGURE_WITH=	libproxy

GNUTLS_DESC=		Use GnuTLS instead of OpenSSL (experimental)
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_WITH=	gnutls

P11_DESC=		PKCS#11 support via libp11
P11_LIB_DEPENDS=	libp11.so:security/libp11

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
