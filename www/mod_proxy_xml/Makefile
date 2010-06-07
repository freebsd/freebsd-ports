# New ports collection Makefile for:	mod_proxy_xml
#
# Date created:		10/01/2007
# Whom:			Dominic Marks <dom@goodforbusiness.co.uk>
#
# $FreeBSD$
#

PORTNAME=	mod_proxy_xml
PORTVERSION=	0.1
CATEGORIES=	www
MASTER_SITES=	http://apache.webthing.com/svn/apache/filters/xmlns/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DISTFILES=	xmlns.h mod_proxy_xml.c

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module for rewriting URI references in XML

MAKE_JOBS_SAFE=	yes

WRKSRC=	${WRKDIR}

USE_GNOME=	libxml2
USE_APACHE=	2.0+

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
AP_INC=	${LOCALBASE}/include/libxml2
AP_LIB=	${LOCALBASE}/lib -lxml2

pre-fetch:
	@${MKDIR} ${WRKDIR}/

post-fetch:
	@${CP} ${DISTDIR}/xmlns.h ${DISTDIR}/mod_proxy_xml.c ${WRKDIR}/

do-extract:
	@${DO_NADA}

.include <bsd.port.mk>
