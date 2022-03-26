# Created by: Dominic Marks <dom@goodforbusiness.co.uk>

PORTNAME=	mod_proxy_xml
PORTVERSION=	0.1
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://apache.webthing.com/svn/apache/filters/xmlns/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DISTFILES=	xmlns.h mod_proxy_xml.c

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module for rewriting URI references in XML

BROKEN=		Doesn't work as intended
DEPRECATED=	Abandoned upstream, last release in 2004
EXPIRATION_DATE=2022-03-31

USE_GNOME=	libxml2
USES=		apache:2.2+ gnome

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
AP_INC=	${LOCALBASE}/include/libxml2
AP_LIB=	${LOCALBASE}/lib -lxml2

pre-extract:
	@${MKDIR} ${WRKSRC}

do-extract:
	@${CP} ${DISTDIR}/xmlns.h ${DISTDIR}/mod_proxy_xml.c ${WRKSRC}

.include <bsd.port.mk>
