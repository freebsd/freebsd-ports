# New ports collection makefile for:	openconnect
# Date created:				03 June 2009
# Whom:					Damian Gerow
#
# $FreeBSD$
#

PORTNAME=	openconnect
PORTVERSION=	4.05
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.infradead.org/pub/openconnect/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	A client for Cisco's AnyConnect SSL VPN

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=	vpnc-script:${PORTSDIR}/sysutils/vpnc-scripts

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls --with-vpnc-script=${LOCALBASE}/sbin/vpnc-script \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
USE_AUTOTOOLS=	aclocal autoconf libtool
USE_GNOME=	gnomehack pkgconfig
USE_GMAKE=	yes
USE_OPENSSL=	yes
MAKE_JOBS_SAFE=	yes
ACLOCAL_ARGS=	-I .
USE_LDCONFIG=	yes
PORTDOCS=	*

MAN8=		openconnect.8

OPTIONS_DEFINE=	PROXY GNUTLS

PROXY_DESC=	Enable automatic proxy configuratio via libproxy
GNUTLS_DESC=	Use GnuTLS instead of OpenSSL(EXPERIMENTAL)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=--with-gnutls
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPROXY}
LIB_DEPENDS+=	proxy:${PORTSDIR}/net/libproxy
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/TODO ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
