# New ports collection makefile for:	mod_dnssd
# Date created:		27 February 2009
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_dnssd
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://0pointer.de/lennart/projects/mod_dnssd/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An Apache module that provides DNS-SD capabilities

LIB_DEPENDS=	avahi-client.3:${PORTSDIR}/net/avahi-app \
    		apr-1.3:${PORTSDIR}/devel/apr

USE_GMAKE=	yes
USE_APACHE=	2.2+
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
