# New ports collection makefile for:	mod_dnssd
# Date created:		27 February 2009
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_dnssd
PORTVERSION=	0.6
PORTREVISION=	6
CATEGORIES=	www
MASTER_SITES=	http://0pointer.de/lennart/projects/mod_dnssd/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An Apache module that provides DNS-SD capabilities

LIB_DEPENDS=	avahi-client.3:${PORTSDIR}/net/avahi-app

MAKE_JOBS_SAFE=  yes

USE_GMAKE=	yes
USE_APACHE=	2.2+
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		APR_CFLAGS="`${LOCALBASE}/bin/apr-1-config --cflags --cppflags --includes`" \
		APR_LIBS="`${LOCALBASE}/bin/apr-1-config --ldflags`"
CONFIGURE_ARGS=	--disable-lynx

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
