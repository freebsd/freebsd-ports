# New ports collection makefile for:	openconnect
# Date created:				03 June 2009
# Whom:					Damian Gerow
#
# $FreeBSD$
#

PORTNAME=	openconnect
PORTVERSION=	3.11
PORTREVISION=	0
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.infradead.org/pub/openconnect/ \
		CRITICAL

MAINTAINER=	dgerow@afflictions.org
COMMENT=	A client for Cisco\'s AnyConnect SSL VPN

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig
MAKE_JOBS_SAFE=	yes
USE_OPENSSL=	yes
USE_OPENSSL_PORT=	yes # Requires modern OpenSSL version

MAN8=		openconnect.8

OPTIONS=	PROXY "Enable automatic proxy configuratio via libproxy"   off

.include <bsd.port.pre.mk>

.if defined(WITH_PROXY)
LIB_DEPENDS+=	proxy.1:${PORTSDIR}/net/libproxy
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/openconnect.html ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/TODO ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
