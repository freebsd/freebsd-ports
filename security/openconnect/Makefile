# Created by: Damian Gerow
# $FreeBSD$

PORTNAME=	openconnect
PORTVERSION=	6.00
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.infradead.org/pub/openconnect/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Client for Cisco's AnyConnect SSL VPN

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=	vpnc-script:${PORTSDIR}/sysutils/vpnc-scripts

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls --with-vpnc-script=${LOCALBASE}/sbin/vpnc-script \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--without-liboath --without-openssl-version-check \
		--without-stoken
USES=		gmake libtool pkgconfig python:build
USE_LDCONFIG=	yes
USE_PYTHON_BUILD=	yes
PORTDOCS=	*

OPTIONS_DEFINE=	PROXY GNUTLS

PROXY_DESC=		Enable automatic proxy configuratio via libproxy
PROXY_LIB_DEPENDS=	libproxy.so:${PORTSDIR}/net/libproxy
PROXY_CONFIGURE_WITH=	libproxy

GNUTLS_DESC=		Use GnuTLS instead of OpenSSL(EXPERIMENTAL)
GNUTLS_LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls
GNUTLS_CONFIGURE_WITH=	gnutls
GNUTLS_USE_OFF=		OPENSSL=yes

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libopenconnect.so.3.3.0

.include <bsd.port.mk>
