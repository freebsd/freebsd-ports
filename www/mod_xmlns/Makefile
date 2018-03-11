# Created by: Dominic Marks <dom@goodforbusiness.co.uk>
# $FreeBSD$

PORTNAME=	mod_xmlns
PORTVERSION=	0.97
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://apache.webthing.com/svn/apache/filters/xmlns/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DISTFILES=	xmlns.h mod_xmlns.c

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module for XML namespaces

LICENSE=	GPLv2

USE_GNOME=	libxml2
USES=		apache:2.2+

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
AP_INC+=	${LOCALBASE}/include/libxml2
AP_LIB+=	${LOCALBASE}/lib -lxml2
SRC_FILE=	mod_xmlns.c

pre-extract:
	@${MKDIR} ${WRKSRC}

do-extract:
	@${CP} ${DISTDIR}/xmlns.h ${DISTDIR}/mod_xmlns.c ${WRKSRC}

.include <bsd.port.mk>
