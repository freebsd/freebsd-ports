# New ports collection makefile for:	openconnect
# Date created:				03 June 2009
# Whom:					Damian Gerow
#
# $FreeBSD$
#

PORTNAME=	openconnect
PORTVERSION=	3.20
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.infradead.org/pub/openconnect/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	A client for Cisco's AnyConnect SSL VPN

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=	vpnc-script:${PORTSDIR}/sysutils/vpnc-scripts

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls --with-vpnc-script=${LOCALBASE}/sbin/vpnc-script
USE_AUTOTOOLS=	aclocal autoconf libtool
USE_GNOME=	gnomehack pkgconfig
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
ACLOCAL_ARGS=	-I .
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
PORTDOCS=	*

MAN8=		openconnect.8

OPTIONS=	PROXY "Enable automatic proxy configuratio via libproxy" off \
		OPENSSLPORT "Use OpenSSL from ports" off

.include <bsd.port.options.mk>

.if defined(WITH_OPENSSLPORT)
WITH_OPENSSL_PORT=	yes
.else
WITH_OPENSSL_BASE=	yes
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_PROXY)
LIB_DEPENDS+=	proxy.1:${PORTSDIR}/net/libproxy
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|libdir)/pkgconfig|prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.am

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/TODO ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
