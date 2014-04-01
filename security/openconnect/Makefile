# Created by: Damian Gerow
# $FreeBSD$

PORTNAME=	openconnect
PORTVERSION=	5.03
PORTREVISION=	2
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
		--without-openssl-version-check
USE_AUTOTOOLS=	aclocal autoconf automake libtool
USES=		gmake pathfix pkgconfig
USE_OPENSSL=	yes
ACLOCAL_ARGS=	-I .
AUTOMAKE_ARGS=	--add-missing
USE_LDCONFIG=	yes
PORTDOCS=	*

OPTIONS_DEFINE=	PROXY GNUTLS

PROXY_DESC=	Enable automatic proxy configuratio via libproxy
GNUTLS_DESC=	Use GnuTLS instead of OpenSSL(EXPERIMENTAL)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=--with-gnutls \
		--with-system-cafile=${LOCALBASE}/share/certs/ca-root-nss.crt
RUN_DEPENDS+=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
BUILD_DEPENDS+=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPROXY}
LIB_DEPENDS+=	proxy:${PORTSDIR}/net/libproxy
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/TODO ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
